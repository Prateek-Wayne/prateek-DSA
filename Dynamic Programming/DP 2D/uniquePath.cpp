#include <bits/stdc++.h>
using namespace std;

int helper(int row,int col)
{
    if(row==0 && col==0)
        return 1;
    if(row<0 || col<0)
        return 0;
    
    int left=helper(row,col-1);
    int right=helper(row-1,col);

    return left+right;
}

int uniquePaths(int m, int n)
{
    int row=m-1;
    int col=n-1;
    return helper(row,col);

}

int main()
{   
    cout<< uniquePaths(3,2);
    return 0;
}