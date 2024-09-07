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

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int minValue(Node* root) {
        // Code here
        while(root!=NULL)
        {
            root=root->left;
        }
        return root->data;
    }

TreeNode *searchBST(TreeNode *root, int val)
{
    while(root!=NULL && root->val!=val)
    {
        root=root->val>val?root->left:root->right;
    }
    return root;
}

int main()
{
}