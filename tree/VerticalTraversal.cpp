#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


struct MyDs
{
    int level;
    int height;
    Node *node;
};

vector<vector<int>> levelOrderTraversal(Node *root)
{
    queue<MyDs> q;
    map<int, vector<int>> mp;
    MyDs firstData;
    firstData.level = 0;
    firstData.height = 0;
    firstData.node = root;
    q.push(firstData);
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        mp[it.level].push_back(it.node->data);
        if (it.node->left)
        {
            MyDs leftData;
            leftData.level = it.level - 1;
            leftData.height = it.height + 1;
            leftData.node = it.node->left;

            q.push(leftData);
        }
        if (it.node->right)
        {
            MyDs rightData;
            rightData.level = it.level + 1;
            rightData.height = it.height + 1;
            rightData.node = it.node->right;
            q.push(rightData);
        }
    }
    vector<vector<int>> ans;

    for (auto i : mp)
    {  
        // sort(i.second.begin(),i.second.end());
        ans.push_back(i.second);
    }
    return ans;
}
vector<vector<int>> verticalTraversal(Node *root)
{

}
int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Perform vertical traversal
    levelOrderTraversal(root);
}
