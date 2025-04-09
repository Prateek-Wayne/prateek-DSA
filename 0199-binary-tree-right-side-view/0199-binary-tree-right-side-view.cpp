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
    void helper(TreeNode* root, int height, map<int, vector<int>>& mp) {
        if (!root)
            return;
        mp[height].push_back(root->val);
        if (root->left)
            helper(root->left, height + 1, mp);
        if (root->right)
            helper(root->right, height + 1, mp);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        map<int, vector<int>> mp;
        helper(root, 0, mp);
        for (auto i : mp)
            ans.push_back(i.second.back());
        return ans;
    }
};