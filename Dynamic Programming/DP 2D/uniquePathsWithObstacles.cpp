#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &obstacleGrid, int row, int col, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0 && obstacleGrid[row][col] != 1)
        return dp[row][col] = 1;
    if (row < 0 || col < 0 || obstacleGrid[row][col] == 1)
        return 0;
    if (dp[row][col] != -1)
        return dp[row][col];

    int left = helper(obstacleGrid, row, col - 1, dp);
    int up = helper(obstacleGrid, row - 1, col, dp);

    return dp[row][col] = left + up;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int row = obstacleGrid.size() - 1;
    int col = obstacleGrid[0].size() - 1;
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, -1));
    return helper(obstacleGrid, row, col, dp);
}
int main()
{
    // vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> obstacleGrid = {{1}};
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}