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
   
void helper(TreeNode *root, long long sum, int targetSum, int &count)
{
    if (!root)
        return;
    sum += root->val;
    if (sum == targetSum)
        count++;
    helper(root->left, sum, targetSum, count);
    helper(root->right, sum, targetSum, count);
}
void iterate(TreeNode *root, int targetSum, int &count)
{
    if (!root)
        return;
    int sum = 0;
    helper(root, sum, targetSum, count);
    iterate(root->left, targetSum, count);
    iterate(root->right, targetSum, count);
}
int pathSum(TreeNode *root, int targetSum)
{
    int count = 0;
    int sum = 0;
    iterate(root, targetSum, count);
    return count;
}

};