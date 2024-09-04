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

struct MyDs{
    int level;
    int height;
    TreeNode *node;
};

void levelOrderTraversal(TreeNode* root)
{
    queue<MyDs> q;
    map<int,vector<int>> mp;
    MyDs firstData;
    firstData.level=0;
    firstData.height=0;
    firstData.node=root;
    q.push(firstData);
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        mp[it.level].push_back(it.node->val);
        if(it.node->left)
        {
            MyDs leftData;
            leftData.level=it.level-1;
            leftData.height=it.height+1;
            q.push(leftData);
        }
        if(it.node->right)
        {
            MyDs rightData;
            rightData.level=it.level+1;
            rightData.height=it.height+1;
            q.push(rightData);
        }
    }
    for(auto i:mp)
    {
        cout<<i.first<<"|";
        for(auto x:i.second)
            cout<<x<<",";
        cout<<endl;
    }
}
int main()
{

    TreeNode *root = new TreeNode();
}
