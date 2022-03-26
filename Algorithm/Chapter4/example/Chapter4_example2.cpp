#include <iostream>

#include <string>
#include <random>
#include <set>
#include <ctime>

#define NODE_COUNT  100
#define NODE_MAX_VALUE  1000000
#define DELETE_SIZE 10

using namespace std;

template<typename T> 
class Node
{
    T data;
    Node *left;
    Node *right;
    Node *parent;

public:

    Node()
    {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    Node(T data)
    {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        this->data = data;
    }

    template<typename t> friend class Tree;
};

template<typename T>
class Tree
{
    Node<T> *root;


    Node<T>* Search(T data, Node<T>* node)
    {
        if( node == nullptr)
            return nullptr;
        if( node->data == data)
            return node;

        Node<T>* nptr;
        if( data > node->data)
            nptr =  Search(data, node->right);
        else
            nptr = Search(data, node->left);
        
        return nptr;
    }

    Node<T>* Successor(Node<T>* node)
    {
        if(node->right != nullptr )
        {
            Node<T> * p = node->right;
            while( p->left != nullptr)
            {
                p = p->left;
            }
            return p;
        }
        
        Node<T> * p = node->parent;
        Node<T> *q = node;
        while( p->left != q)
        {
            q= p;
            p = p->parent;
        }
        return p;            
    
    }
    
    void Delete(Node<T> *del)
    {
        Node<T> *p;
        if(del->left == nullptr && del->right == nullptr)
            p = del;
        else
            p = Successor(del);

        Node<T> *q;
        if( p->left != nullptr)
            q = p->left;
        else
            q = p->right;

        if( q != nullptr )
            q->parent = p->parent;

        if( p->parent == nullptr )
            root = q;
        else if( p == p->parent->left )
            p->parent->left = q;
        else
            p->parent->right = q;
        
        if( p != del)
        {
            del->data = p->data;            
        }
    }


public:
    Tree()
    {
        root = nullptr;
    }
    Tree(T data)
    {
        root = new Node<T>(data);
    }

    void Insert(T data)
    {
        if(root == nullptr)
        {
            root = new Node<T>(data);
            return;
        }

        Node<T> *p = root;
        Node<T> *q = p;

        while( p!= nullptr )
        {
            q = p;
            if (p->data < data)
                p = p->right;
            else
                p = p->left;
        }
        
        Node<T> *r = new Node<T>(data);
        r->parent = q;

        if( q->data < data)
            q->right = r;
        else
            q->left = r;

    }


    Node<T>* Search(T data)
    {
        return Search(data, root);
    } 


    Node<T>* Delete(T data)
    {
        Node<T> *p = Search(data);
        if(p!= nullptr)
            Delete(p);
        return p;
    }
    void display()
    {
        display(root,0);
    }

    void display(Node<T> *start, int step = 0)
    {
        if(start == nullptr)
            return;

        if(step != 0)
        {
            for(int i = 0 ; i< step; i++)
                cout<<"   ";
            cout<< "└";
            if(start->parent->left == start)
                cout<<"(L)  ";
            else
                cout<<"(R)  ";

        }
        cout<< start->data<<endl;

        display(start->left, step+1);
        display(start->right, step+1);

    }

};




int main()
{
    // random_device rd;
    mt19937 gen( (unsigned int)time(NULL) );
    uniform_int_distribution<int> dist(1, NODE_MAX_VALUE);
    uniform_int_distribution<int>   rand_ind(0, NODE_COUNT-1);
    
    set<int> inds;
    vector<int> target;

    Tree<int> bst;

    while(inds.size() != DELETE_SIZE)
    {
        inds.insert(rand_ind(gen));
    }

    set<int>::iterator index = inds.begin();

    cout<<"1 ~ "<< NODE_MAX_VALUE <<"사이의 임의 "<< NODE_COUNT<<"개 추가"<<endl;


    for(int i = 0; i< NODE_COUNT; i++)
    {
        int num = dist(gen);
        bst.Insert(num);
        if( *index == i )
        {
            target.push_back(num);
            index++;
        }
    }
    
    bst.display();
    
    
    cout<<"삭제할 " << DELETE_SIZE <<"개"<<endl;

    for(int i = 0 ; i< target.size(); i++)
    {
        cout<< target[i]<<"\t";
    }
    cout<<endl;

    for(int t : target)
    {
        bst.Delete(t);
    }

    cout<<"삭제 후 "<<endl;
    bst.display();
    


}