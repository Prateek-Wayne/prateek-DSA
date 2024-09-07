#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void topView(TreeNode *root)
{
    queue<pair<int,TreeNode>>q;
    map<int,vector<int>> mp;
    if(root!=NULL)
        q.push({0,*root});
    while(!q.empty())
    {
        // pair<int,Node> temp=q.front();
        auto temp=q.front();
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
        cout<<i.first<<" :";
        for(auto x:i.second)
            cout<<x<<"|";
        cout<<endl;
    }
    vector<int> ans;
    for(auto i:mp)
    {
        ans.push_back(i.second[i.second.size()-1]);
    }
    // return ans;
}

int main() {
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(3);
    root->right->right = new Node(6);
    root->right->right->right = new Node(5);

    topView(root);

    return 0;
}