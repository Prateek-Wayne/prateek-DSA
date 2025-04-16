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
    int amountOfTime(TreeNode* root, int start) {
        // parent storing
        map<TreeNode*, TreeNode*> mp;
        queue<TreeNode*> qt;
        qt.push(root);
        TreeNode* startPoint;
        while (!qt.empty()) {
            int size = qt.size();
            for (int i = 0; i < size; i++) {
                auto top = qt.front();
                qt.pop();
                if (top->val == start)
                    startPoint = top;
                if (top->left) {
                    mp[top->left] = top;
                    qt.push(top->left);
                }
                if (top->right) {
                    mp[top->right] = top;
                    qt.push(top->right);
                }
            }
        }
        int height = 0;
        set<TreeNode*> visited;
        qt.push(startPoint);
        visited.insert(startPoint);
        while (!qt.empty()) {
            int size = qt.size();
            for (int i = 0; i < size; i++) {
                auto top = qt.front();
                qt.pop();
                if (top->left && !visited.count(top->left)) {
                    visited.insert(top->left);
                    qt.push(top->left);
                }
                if (top->right && !visited.count(top->right)) {
                    visited.insert(top->right);
                    qt.push(top->right);
                }
                if (mp.count(top) && !visited.count(mp[top])) {
                    visited.insert(mp[top]);
                    qt.push(mp[top]);
                }
            }
            height++;
        }
        return height-1;
    }
};