#include <iostream>
#include <vector>
#include <string>

using namespace std;

class node
{
    char data;
    int left;
    int right;
public:
    node()
    {
        left = 0;
        right = 0;
    }
    node(char c)
    {
        data = c;
        left = 0;
        right = 0;
    }

    void setChild(int c)
    {
        if( left == 0)
            setLeft(c);
        else   
            setRight(c);
    }

    void setLeft(int l)   {    left = l;    }
    void setRight(int r)  {    right = r;    }
    void setData(char c)    {    data = c;    }

    int getLeft()     {   return left;    }
    int getRight()    {   return right;    }
    char getData()      {    return data;    }

};

vector<string> splitString(string str)
{
    vector<string> temp;
    string s = "";
    for(char c : str)
    {
        if (c == ' ')
        {
            temp.push_back(s);
            s = "";
        }
        else
            s+=c;
    }
    temp.push_back(s);
    return temp;
}

string inorderTrace(vector<node> tree, int root)
{
    if( root == 0)
        return "";

    string str="";
    str += inorderTrace(tree,tree[root].getLeft());
    str += tree[root].getData();
    str += inorderTrace(tree,tree[root].getRight());
    
    return str;
}



int main()
{
    int T=10;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        cin>>n;
        vector<node> nodes;
        node temp;
        for(int i = 0; i<n+1; i++)
            nodes.push_back(temp);

        cin.ignore();
        for(int i =0 ; i<n; i++)
        {
            string str;
            getline(cin,str);

            vector<string> sp = splitString(str);

            nodes[i+1].setData(sp[1][0]);
            if( sp.size() > 2)
            {
                for(int j = 2; j<sp.size(); j++)
                {
                    nodes[i+1].setChild(stoi(sp[j]));
                }
            }
        }

        string inorder = inorderTrace(nodes,1); 

        cout<<"#"<<testCase<<" "<<inorder<<endl;
    }
    return 0;
}
