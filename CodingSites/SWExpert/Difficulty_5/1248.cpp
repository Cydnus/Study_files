#include <iostream>
#include <vector>
#include <map>

using namespace std;

class node
{
    int no;
    node* left;
    node* right;
    node* parent;

    public :
    node()
    {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
    node(int no)
    {
        this->no = no;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
    void setChild(node* node)
    {
        if(left == nullptr)
        {
            left = node;
            node->parent = this;
            return;
        }
        
        right = node;
        node->parent = this;
    }

    vector<int> getParents()
    {
        node* p = parent;
        vector<int> parents;
        parents.push_back(no);
        while(p != nullptr)
        {
            parents.insert(parents.begin(),p->no);
            p = p->parent;
        }
        return parents;
    }
    friend int getCountOfSubTree(node*);
};


map<int, node*> tree;


int getCommonParent(int VA, int VB)
{
    vector<int> parentOfA, parentOfB;
        
    parentOfA = tree[VA]->getParents();
    parentOfB = tree[VB]->getParents();

    int common_parent=1;

    for(int i = 0; i < parentOfA.size() && i < parentOfB.size(); i++ )
    {
        if( parentOfA[i] != parentOfB[i])
        {
            common_parent = parentOfA[i-1];
            break;
        }
    }
    return common_parent;
}


void init_Tree(int countOfVertex, int countOfLine)
{    
    tree.clear();
    for(int i = 1 ; i<=countOfVertex; i++)
        tree[i] = new node(i);
        
    for(int i = 0; i<countOfLine; i++)
    {
        int p, c;
        cin>>p>>c;
        tree[p]->setChild(tree[c]);
    }
}

int getCountOfSubTree(node* root)
{
    if( root == nullptr)
        return 0;
    int left = getCountOfSubTree(root->left);
    int right = getCountOfSubTree(root->right);
    
    return left + right +1;
}


int main()
{
    freopen("not_input_1248.txt","r",stdin);
    
    int T;
    cin>>T;

    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int countOfVertex, countOfLine, VA, VB;
        cin>>countOfVertex >> countOfLine >> VA >> VB;
        
        init_Tree(countOfVertex, countOfLine);

        int common_parent = getCommonParent(VA, VB);
        int countOfSubTree = getCountOfSubTree(tree[common_parent]);

        cout<<"#"<<testCase<<" "<<common_parent<<" "<<countOfSubTree<<endl;
    }
    return 0;
}
