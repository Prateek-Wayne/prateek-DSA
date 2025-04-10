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
    void helper(TreeNode* root, vector<int> ds, vector<vector<int>>& ans,
                int targetSum) {
        if (!root)
            return;
        ds.push_back(root->val);
        if (!root->left && !root->right) {
            int sum = accumulate(ds.begin(), ds.end(), 0);
            if (sum == targetSum)
                ans.push_back(ds);
            return;
        }
        helper(root->left, ds, ans, targetSum);
        helper(root->right, ds, ans, targetSum);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        helper(root, {}, ans, targetSum);
        return ans;
    }
};