#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSymmetric(TreeNode *root)
{
    map<int, vector<int>> mp;
    queue<pair<int, TreeNode>> q;
    if (root)
        q.push({0, *root});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        if (it.second.val == INT_MIN)
        {
            mp[it.first].push_back(INT_MIN);
            continue;
        }
        mp[it.first].push_back(it.second.val);
        if (it.second.left)
        {
            q.push({it.first + 1, *it.second.left});
        }
        if (it.second.left == NULL)
        {
            q.push({it.first + 1, *new TreeNode(INT_MIN)});
        }
        if (it.second.right)
        {
            q.push({it.first + 1, *it.second.right});
        }
        if (it.second.right == NULL)
        {
            q.push({it.first + 1, *new TreeNode(INT_MIN)});
        }
    }
    for (auto vec : mp)
    {
       if(!equal(vec.second.begin(), vec.second.begin() + vec.second.size() / 2, vec.second.rbegin()))
        return false;
    }
    return true;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    // root->right = new TreeNode(2);
    // root->left->right = new TreeNode(3);
    // root->right->right = new TreeNode(3);
//     TreeNode* root = new TreeNode(1);
// root->left = new TreeNode(2);
// root->right = new TreeNode(2);
// root->left->left = new TreeNode(3);
// root->left->right = new TreeNode(4);
// root->right->left = new TreeNode(4);
// root->right->right = new TreeNode(3);
    cout<<isSymmetric(root);
}