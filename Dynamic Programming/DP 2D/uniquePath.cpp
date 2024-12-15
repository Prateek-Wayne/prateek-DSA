#include <bits/stdc++.h>
using namespace std;

int helper(int R,int C,int m ,int n,vector<vector<int>> &dp)
{
    if(R==m && C==n)
    {
        dp[R][C]=1;
        return 1;
    }
    if(dp[R][C]!=-1)
        return dp[R][C];
    int path=0;
    if(R+1<=m)
    {  
        path+=helper(R+1,C,m,n,dp);
        dp[R][C]=path;
    }
    if(C+1<=n)
    {
        path+=helper(R,C+1,m,n,dp);
        dp[R][C]=path;
    }
    return path;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(0, 0, m - 1, n - 1,dp);
}

int main()
{   
    cout<< uniquePaths(3,7);
    return 0;
}