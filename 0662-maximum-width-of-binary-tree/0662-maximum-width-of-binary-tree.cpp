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
int widthOfBinaryTree(TreeNode *root)
{
    typedef unsigned long long ll;

    ll ans = 0;
    queue<pair<TreeNode *, ll>> qt;
    if (!root)
        return 0;
    qt.push({root, 0});
    while (!qt.empty())
    {
        int size = qt.size();
        ll back = qt.back().second;
        ll front = qt.front().second;
        ll length = back - front + 1;
        ans = max(ans, length);
        for (int i = 0; i < size; i++)
        {
            auto top = qt.front();
            qt.pop();
            ll level = top.second * 2;
            if (top.first->left)
            {
                qt.push({top.first->left, level + 1});
            }
            if (top.first->right)
            {
                qt.push({top.first->right, level + 2});
            }
        }
    }
    return ans;
}
};