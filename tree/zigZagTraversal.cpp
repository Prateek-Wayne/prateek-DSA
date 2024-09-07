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

void zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    queue<pair<int,TreeNode>> q;
    map<int,vector<int>> mp;
    if(root!=NULL)
        q.push({0,*root});
    while(!q.empty())
    {
        pair<int,TreeNode> temp=q.front();
        q.pop();
        mp[temp.first].push_back(temp.second.val);
        if(temp.second.left)
        {
            q.push({temp.first+1,*temp.second.left});
        }
        if(temp.second.right)
        {
            q.push({temp.first+1,*temp.second.right});
        }
    }
      for(auto i:mp)
    {   
        if(i.first%2==0)
        {
            ans.push_back(i.second);
        }
        else
        {   
            reverse(i.second.begin(),i.second.end());
            ans.push_back(i.second);
        }
    }
    for(auto i:ans)
    {
        
        for(auto x:i)
            cout<<x<<"|";
        cout<<endl;
    }
}

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Testing the zigZagTraversal function
    zigzagLevelOrder(root);

    return 0;
}