/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
bool helper(TreeNode *root, int sum, int targetSum)
{
    if (!root)
        return false;
    sum += root->val;
    if (!root->left && !root->right)
    {
        if (sum == targetSum)
            return true;
        return false;
    }
    bool left = helper(root->left, sum, targetSum);
    bool right = helper(root->right, sum, targetSum);
    return left || right;
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (!root)
        return false;
    return helper(root, 0, targetSum);
}
};