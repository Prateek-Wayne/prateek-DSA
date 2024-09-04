#include<bits/stdc++.h>
using namespace std;

struct Tree
{
    /* data */
    int data;
    Tree *Left;
    Tree *Right;

    Tree(int val){
        data=val;
        Left=NULL;
        Right=NULL;
    }
};


int main()
{
    struct Tree *root= new Tree(5);
    root->Left=new Tree(1);
    root->Right=new Tree(19);


}