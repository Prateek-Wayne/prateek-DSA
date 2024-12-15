#include <bits/stdc++.h>
using namespace std;

int helper(int R,int C,int m ,int n)
{
    if(R==m && C==n)
        return 1;
    int path=0;
    if(R+1<=m)
    {  
        path+=helper(R+1,C,m,n);
    }
    if(C+1<=n)
        path+=helper(R,C+1,m,n);
    return path;
}

int uniquePaths(int m, int n)
{
    return helper(0, 0, m - 1, n - 1);
}

int main()
{   
    cout<< uniquePaths(3,7);
    return 0;
}