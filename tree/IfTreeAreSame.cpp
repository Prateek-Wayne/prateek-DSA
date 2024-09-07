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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p != nullptr && q != nullptr)
    {
        // Check if the current node values are different
        if (p->val != q->val)
            return false;
        
        // Recursively check the left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    
    // If one is NULL and the other is not, the trees are not the same
    else if (p != nullptr && q == nullptr)
        return false;
    else if (p == nullptr && q != nullptr)
        return false;
    
    // If both are NULL, the trees are the same at this node
    return true;
}

int main()
{
}