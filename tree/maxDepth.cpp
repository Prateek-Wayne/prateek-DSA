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
int maxDepth(TreeNode *root)
{
    if(root!=NULL)
    {
        int left=1+maxDepth(root->left);
        int right=1+maxDepth(root->right);
        return max(left,right);
    }
    return 0;

}
int main()
{
    TreeNode *root = new TreeNode();

    cout << maxDepth(root);
}