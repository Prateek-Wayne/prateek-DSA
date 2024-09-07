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
TreeNode *insertIntoBST(TreeNode *root, int key)
{
    TreeNode ans = *new TreeNode();
    while (root != NULL)
    {
        if(root->val<=key)
        {
            ans=max(ans.val,root->val);
        }
        root = root->val >= key ? root->left : root->right;
    }
    TreeNode *temp=new TreeNode();
    temp->right=ans.right;
    ans.right=temp;
   temp->val=key;
    return root;

}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Create a simple BST
    TreeNode* root = new TreeNode(4);
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