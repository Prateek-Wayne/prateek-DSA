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
int count=0;
 int kthSmallest(TreeNode* root, int &k) {
        if(root!=NULL)
        {
            return kthSmallest(root->left,k);
            k--;
            if(k==0)
                return root->val;
            return kthSmallest(root->right,k);
        }
        return -1;
    }

TreeNode *insertIntoBST(TreeNode *root, int key)
{
    if (root == NULL)
    {
        return new TreeNode(key);
    }

    TreeNode *current = root;
    while (true)
    {
        if (key < current->val)
        {
            if (current->left == NULL)
            {
                current->left = new TreeNode(key);
                break;
            }
            else
            {
                current = current->left;
            }
        }
        else
        {
            if (current->right == NULL)
            {
                current->right = new TreeNode(key);
                break;
            }
            else
            {
                current = current->right;
            }
        }
    }
    return root;
}

void inorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    // Create a simple BST
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Insert a new value into the BST
    int key = 5;
    root = insertIntoBST(root, key);

    // Print the tree in-order to verify the insertion
    inorderTraversal(root);
    cout << endl;

    return 0;
}