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

void isSymmetric(TreeNode *root)
{
    map<int, vector<int>> mp;
    queue<pair<int, TreeNode>> q;
    if (root)
        q.push({0, *root});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        if (it.second.val == -1)
        {
            mp[it.first].push_back(0);
            continue;
        }
        mp[it.first].push_back(it.second.val);
        if (it.second.left)
        {
            q.push({it.first + 1, *it.second.left});
        }
        if (it.second.left == NULL)
        {
            q.push({it.first + 1, *new TreeNode(-1)});
        }
        if (it.second.right)
        {
            q.push({it.first + 1, *it.second.right});
        }
        if (it.second.right == NULL)
        {
            q.push({it.first + 1, *it.second.right});
        }
    }
    for (auto i : mp)
    {
        cout << i.first << " :";
        for (auto x : i.second)
            cout << x << "|";
        cout << endl;
    }
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(3);
    isSymmetric(root);
}