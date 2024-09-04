#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<int> levelOrder(Node *root)
{
    queue<Node*> q; // Change the type of the queue to hold pointers to Node objects
    vector<int> ans;
    q.push(root);
    while(!q.empty())
    {
       Node *i=q.front();
       q.pop();
       ans.push_back(i->data);
       if(i->left)
       {
        q.push(i->left);
       }
       if(i->right)
        q.push(i->right);
    }
    return ans;
}

int main()
{
}