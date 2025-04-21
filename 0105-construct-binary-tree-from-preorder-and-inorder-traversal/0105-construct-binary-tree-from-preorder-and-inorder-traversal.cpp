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

TreeNode *helper(vector<int> &inorder, int iStart, int iEnd, vector<int> &preorder, int pStart, int pEnd, map<int, int> &mp)
{
    if (iStart > iEnd || pStart > pEnd)
        return NULL;
    TreeNode *root = new TreeNode(preorder[pStart]);
    int rootIndex = mp[preorder[pStart]];
    int numLeft = rootIndex - iStart;
    root->left = helper(inorder, iStart, rootIndex - 1, preorder, pStart + 1, pStart + numLeft, mp);
    root->right = helper(inorder, rootIndex + 1, iEnd, preorder, pStart + numLeft + 1, pEnd, mp);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> mp;
    int n = inorder.size();
    for (int i = 0; i < n; i++)
    {
        mp[inorder[i]] = i;
    }

    TreeNode *root = helper(inorder, 0, n - 1, preorder, 0, n - 1,mp);
    return root;
}
};