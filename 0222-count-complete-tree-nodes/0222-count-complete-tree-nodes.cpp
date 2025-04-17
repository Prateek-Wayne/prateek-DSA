/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

void height(TreeNode *root, int &h, bool leftDir)
{
    if (!root)
        return;
    h++;
    if (leftDir)
        height(root->left, h, leftDir);
    else
        height(root->right, h, leftDir);
}

int countNodes(TreeNode *root)
{
    if (!root)
        return 0;
    int leftHeight = 0;
    height(root, leftHeight, true);
    int rightHeight = 0;
    height(root, rightHeight, false);
    if (leftHeight == rightHeight)
        return (1 << leftHeight) - 1;
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}
};