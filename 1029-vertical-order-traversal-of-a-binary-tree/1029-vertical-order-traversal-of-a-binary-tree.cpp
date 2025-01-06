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
    void helper(TreeNode* root, int vertical, int level,
                map<int, map<int, vector<int>>>& mp) {
        if (!root)
            return;
        mp[vertical][level].push_back(root->val);
        helper(root->left, vertical - 1, level + 1, mp);
        helper(root->right, vertical + 1, level + 1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;
        vector<vector<int>> ans;
        helper(root, 0, 0, mp);
        for (auto i : mp) {
            vector<int> temp;
            for (auto j : i.second) {
                vector<int> temp2(j.second.begin(), j.second.end());
                sort(temp2.begin(), temp2.end());
                for (auto x : temp2)
                    temp.push_back(x);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};