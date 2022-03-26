#include <iostream>

#include <queue>
#include <string>

using namespace std;

class node
{
    node* left;
    node* right;
    string data;

public:

    node()
    {
        left = nullptr;
        right = nullptr;
    }
    node(string _data)
    {
        left = nullptr;
        right = nullptr;
        data = _data;
    }

    void setLeft(string _data)
    {
        left = new node(_data);
    }
    
    void setLeft(node* nptr)
    {
        left = nptr;
    }
    
    void setRight(string _data)
    {
        right = new node(_data);
    }
    
    void setRight(node* nptr)
    {
        right = nptr;
    }

    friend class bst;
};


class bst
{
    node* root;

public:
    bst()
    {
        root = nullptr;
    }
    
    bst(string data)
    {
        root = new node(data);
    }
    bst(node* data)
    {
        root = data;
    }
  

    void insert(string data)
    {
        if(root == nullptr)
        {
            root = new node(data);
            return;
        }

        node* p = root;
        node* q = p;
        while( p != nullptr)
        {
            q = p;
            if( p->data > data)
                p = p->left;
            else
                p = p->right;
        }

        if( q->data > data)
            q->setLeft(data);
        else
            q->setRight(data);

    }


    void preorder( node *start = nullptr, bool tmp=true)
    {
        if( start == nullptr && tmp )
        {
            preorder(root);
            return;
        }

        if( start == nullptr)
            return;

        cout<<start->data<<"\t";

        preorder(start->left,false);

        preorder(start->right,false);
    }

    void postorder( node *start = nullptr, bool tmp=true)
    {
        if( start == nullptr && tmp )
        {
            postorder(root);
            return;
        }

        if( start == nullptr)
            return;

        postorder(start->left,false);

        postorder(start->right,false);

        cout<<start->data<<"\t";

    }

    void inorder( node *start = nullptr, bool tmp=true)
    {
        if( start == nullptr && tmp )
        {
            inorder(root);
            return;
        }
        
        if( start == nullptr)
            return;

        inorder(start->left,false);

        cout<<start->data<<"\t";

        inorder(start->right,false);
    }

    void levelorder()
    {
        queue<node *> que;

        que.push(root);

        while(!que.empty())
        {
            node* p = que.front();
            que.pop();

            cout<<p->data<<"\t";
            
            if(p->left != nullptr )
                que.push(p->left);
            if(p->right != nullptr)
                que.push(p->right);

        }

    }

};



int main()
{
    bst *tree = new bst();

    tree->insert("fox");
    tree->insert("bear");
    tree->insert("ant");
    tree->insert("dog");
    tree->insert("cat");
    tree->insert("eagle");
    tree->insert("goose");
    tree->insert("hippo");
    tree->insert("iguana");

    cout<<"Inorder"<<endl;
    tree->inorder();
    cout<<endl;

    cout<<"Preorder"<<endl;
    tree->preorder();
    cout<<endl;
    
    cout<<"Postorder"<<endl;
    tree->postorder();
    cout<<endl;
    
    cout<<"Levelorder"<<endl;
    tree->levelorder();
    cout<<endl;
    
}