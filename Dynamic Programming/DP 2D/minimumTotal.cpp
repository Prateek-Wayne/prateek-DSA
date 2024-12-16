#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &triangle, int R, int C,vector<vector<int>> &dp)
{
    if (R == triangle.size() - 1)
    {
        dp[R][C]=triangle[R][C];
        return triangle[R][C];
    }
    if(dp[R][C]!=-1)
        return dp[R][C];
    int left=triangle[R][C]+helper(triangle,R+1,C,dp);
    int right=triangle[R][C]+helper(triangle,R+1,C+1,dp);
    return dp[R][C]= min(left,right);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int R = 0;
    int C = 0;
    vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),-1));
    return helper(triangle, R, C,dp);
}
int main()
{
    // vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    // vector<vector<int>> triangle ={{-10}};
    vector<vector<int>> triangle ={{-1},{-2,-3}};
    cout << minimumTotal(triangle) << endl;
    return 0;
}