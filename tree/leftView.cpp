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


//Function to return a list containing elements of left view of the binary tree.
void leftTraversal(Node *root,int level,vector<int> *v)
{
    if(root!=NULL)
    {
        if(v->size()==level)
        {
            v->push_back(root->data);
        }
        leftTraversal(root->left,1+level,v);
        leftTraversal(root->right,1+level,v);
    }

}

vector<int> leftView(Node *root)
{   
    vector<int> v;
    leftTraversal(root,0,&v);
    return v;

}
int main()
{
    
}