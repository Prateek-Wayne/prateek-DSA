/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> mp;
        queue<TreeNode*> qt;
        qt.push(root);
        while (!qt.empty()) {

            int size = qt.size();
            for (int i = 0; i < size; i++) {
                auto top = qt.front();
                qt.pop();
                if (top->left) {
                    qt.push(top->left);
                    mp[top->left] = top;
                }
                if (top->right) {
                    qt.push(top->right);
                    mp[top->right] = top;
                }
            }
        }
        set<TreeNode*> visited;
        visited.insert(target);
        qt.push(target);
        int count = 0;
        while (!qt.empty()) {
            int size = qt.size();
            if (count == k)
                break;
            for (int i = 0; i < size; i++) {
                auto top = qt.front();
                qt.pop();
                if (top->left && !visited.count(top->left)) {
                    qt.push(top->left);
                    visited.insert(top->left);
                }
                if (top->right && !visited.count(top->right)) {
                    qt.push(top->right);
                    visited.insert(top->right);
                }
                if (mp.count(top) && !visited.count(mp[top])) {
                    qt.push(mp[top]);
                    visited.insert(mp[top]);
                }
            }
            count++;
        }
        vector<int> ans;
        while (!qt.empty()) {
            auto top = qt.front();
            qt.pop();

            ans.push_back(top->val);
        }
        return ans;
    }
};