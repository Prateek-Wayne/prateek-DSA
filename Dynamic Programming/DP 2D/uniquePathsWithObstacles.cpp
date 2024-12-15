#include<bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& obstacleGrid,int R,int C,vector<vector<int>> &dp)
{
    if(R==obstacleGrid.size()-1 && C==obstacleGrid[0].size()-1 && obstacleGrid[R][C]!=1)
    {
        dp[R][C]=1;
        return 1;
    }
    if(dp[R][C]!=-1)
        return dp[R][C];
    int path=0;
    if(R+1<obstacleGrid.size())
    {   
        if(obstacleGrid[R][C]!=1)
            path+=helper(obstacleGrid,R+1,C,dp);
    }
    if(C+1<obstacleGrid[0].size())
    {
        if(obstacleGrid[R][C]!=1)
            path+=helper(obstacleGrid,R,C+1,dp);
    }
    dp[R][C]=path;
    return path;

}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int R=0;
    int C=0;
    vector<vector<int>> dp(obstacleGrid.size(),vector<int> (obstacleGrid[0].size(),-1));

        return helper(obstacleGrid,R,C,dp);
    }

int main()
{
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    // vector<vector<int>> obstacleGrid =  {{0,0},{0,1}};
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;
 return 0;
}