#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traverse(TreeNode *root,int *level,set<int> *st)
{
    if(root!=NULL)
    {
        if(root->left)
        {    
            st->insert(*level);
            traverse(root->left,level--,st);
        }
        else if(root->right)
        {
            st->insert(*level);
            traverse(root->right,level++,st);
        }
    }
    return;
}

int diameterOfBinaryTree(TreeNode *root)
{
    set<int> st;
    traverse(root,0,&st);
    return *st.rbegin()-*st.begin();
}

int main()
{

    TreeNode *root = new TreeNode();
}
