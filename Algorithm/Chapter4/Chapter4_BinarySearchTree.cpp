#include <iostream>

#include <vector>
#include <queue>

using namespace std;



template <typename t>
class node
{
private:
    t data;
    node* left;
    node* right;
    node* parent;
public:
    node(){}
    node( t d )
    {
        data = d;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    ~node(){};

    t getData()
    {
        return data;
    }
    template< typename T > friend class BinarySearchTree;
};

template <typename T>
class BinarySearchTree
{
private:

    node<T> *root;

public :
    BinarySearchTree()
    {
        root = NULL;
    }
    void insert(T data)
    {
        node<T> *q = new node<T>(data);

        if( root == NULL)
        {
            root = q;
            return;
        }

        node<T> *p = root;
        node<T> *pre = root;
        int is_right = 0;
        while(p != NULL)
        {
            pre = p;
            if( p->data > data)
            {
                p = p->left;
                is_right = 0;
            }
            else
            {
                p = p->right;
                is_right = 1;
            }
        }

        if(is_right == 1)
            pre->right = q;
        else
            pre->left = q;

        q->parent = pre;
    }

    void display()
    {
        display(root,0);
    }

    void display(node<T> *start, int step = 0)
    {
        if(start == NULL)
            return;

        if(step != 0)
        {
            for(int i = 0 ; i< step; i++)
                cout<<"   ";
            cout<< "¦¦";
            if(start->parent->left == start)
                cout<<"(L)  ";
            else
                cout<<"(R)  ";

        }
        cout<< start->data<<endl;

        display(start->left, step+1);
        display(start->right, step+1);

    }


    string PreOrderTrace()
    {
        return PreOrderTrace(root);
    }

    string PreOrderTrace(node<T> *np)
    {
        if( np == NULL)
            return "";


        string temp ="";
        temp += to_string(np->data);
        temp += " ";
        temp += PreOrderTrace(np->left);
        temp += PreOrderTrace(np->right);
        return temp;
    }

    string PostOrderTrace()
    {
        return PostOrderTrace(root);
    }

    string PostOrderTrace(node<T> *np)
    {
        string temp ="";
        if( np == NULL)
            return "";

        temp += PostOrderTrace(np->left);
        temp += PostOrderTrace(np->right);
        temp += to_string(np->data);
        temp += " ";
        return temp;
    }
    string InOrderTrace()
    {
       return InOrderTrace(root);
    }

    string InOrderTrace(node<T> *np)
    {
        string temp ="";
        if( np == NULL)
            return "";

        temp += InOrderTrace(np->left);
        temp += to_string(np->data);
        temp += " ";
        temp += InOrderTrace(np->right);
        return temp;
    }

    node<T>* Search(T data)
    {
        return rec_Search(data, root);
    }
    node<T>* rec_Search(T data, node<T>* check)
    {
        if( check == NULL || check->data == data)
            return check;

        if( data < check->data)
            return rec_Search(data, check->left);
        return rec_Search(data, check->right);
    }


    node<T>* Maximum(node<T>* np)
    {
        node<T>* p = np;
        while(p->right != NULL)
        {
            p = p->right;
        }
        return p;
    }

    node<T>* Minimum(node<T>* np)
    {
        node<T>* p = np;
        while(p->left != NULL)
        {
            p = p->left;
        }
        return p;
    }


    node<T>* successor(node<T>* np)
    {
        if( np->right != NULL)
            return Minimum(np->right);

        node<T>* p = np->parent;
        node<T>* q = np;

        while(p != NULL && q == p->right)
        {
            q = p;
            p = p->parent;
        }
        return p;

    }

    void Remove(node<T>* np)
    {
        if( root == NULL)
            return;

        node<T>* target = np-> left;
        if( np->left == NULL)
            target = np->right;

        if( np-> left != NULL && np->right != NULL)
        {
            node<T>* p = Minimum(np->right);

            if(p->right != NULL)
            {
                p->right->parent = p->parent;
                if( p->parent->left == p )
                     p->parent->left = p->right;
            }

            p-> left = np->left;
            p-> left->parent = p;

            if( p != np->right)
                p->right = np->right;

            if( np == root)
                root = p;
            else
                target = p;

        }

            if(np == root)
                root = target;
            if(target!=NULL)
                target->parent = np->parent;
            if( np->parent->left == np )
                 np->parent->left = target;
            else if( np->parent->right == np )
                 np->parent->right = target;


        delete np;
    }

    string Level_Trace()
    {
        node<T> *p = root;

        queue< node<T>* > que;
        que.push(p);

        string str = "";
        
        while(!que.empty())
        {
            node<T> *q = que.front();
            que.pop();

            str += to_string(q->data);
            str += " ";

            if( q->left != NULL)
                que.push(q->left);
            if(q->right != NULL)
                que.push(q->right);
        }
        
        return str;

    }

};






int main()
{
    BinarySearchTree<int> *bst = new BinarySearchTree<int>();
    bst->insert(10);
    bst->insert(50);
    bst->insert(20);
    bst->insert(7);
    bst->insert(3);
    bst->insert(15);
    bst->insert(25);

    bst->display();

    cout<<endl;
    cout<<"PreOrderTrace"<<endl;
    cout<<endl;

    cout<< bst->PreOrderTrace() <<endl;

    cout<<endl;
    cout<<"InOrderTrace"<<endl;
    cout<<endl;

    cout<< bst->InOrderTrace()<<endl;

    cout<<endl;
    cout<<"PostOrderTrace"<<endl;
    cout<<endl;

    cout<< bst->PostOrderTrace()<<endl;

    cout<<endl;

    
    cout<<endl;
    cout<<"LevelOrderTrace"<<endl;
    cout<<endl;

    cout<< bst->Level_Trace()<<endl;

    cout<<endl;
    cout<<"search"<<endl;

    node<int>* np =  bst->Search(20);
    cout<< np->getData()<<endl;

    cout<<"remove"<<endl;
    cout<<endl;
    bst->Remove(np);
    bst->display();


}