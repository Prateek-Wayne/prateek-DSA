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

void helper(TreeNode *root, vector<int> ds, vector<string> &ans)
{
    if (!root)
        return;
    ds.push_back(root->val);
    if (!root->left && !root->right)
    {
        string s = "";
        for (int i = 0; i < ds.size() - 1; i++)
        {
            s += to_string(ds[i]) + "->";
        }
        s += to_string(ds[ds.size() - 1]);
        ans.push_back(s);

        return;
    }
    helper(root->left, ds, ans);
    helper(root->right, ds, ans);
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> ds;
        if (!root)
            return ans;
        helper(root, ds, ans);
        return ans;
    }
};