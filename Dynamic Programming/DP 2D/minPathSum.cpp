#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &grid,int R,int C,vector<vector<int>> &dp)
{
    if(R==grid.size()-1 && C==grid[0].size()-1)
    {
        dp[R][C]=grid[R][C];
        return grid[R][C];
    }

    if(dp[R][C]!=-1)
        return dp[R][C];
    int left=INT_MAX;
    if(R<grid.size()-1)
    {
        left=helper(grid,R+1,C,dp)+grid[R][C];
    }
    int right=INT_MAX;
    if(C<grid[0].size()-1)
    {
        right=helper(grid,R,C+1,dp)+grid[R][C];
    }
    return dp[R][C]= min(left,right);
}

int minPathSum(vector<vector<int>> &grid)
{
    int R=0;
    int C=0;
    vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size(),-1));
    return helper(grid,R,C,dp);
}
int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    // vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
    cout << minPathSum(grid) << endl;
    return 0;
}