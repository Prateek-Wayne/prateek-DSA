#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
        return grid[row][col];

    if (row < 0 || col < 0)
        return INT_MAX - 10000;

    if (dp[row][col] != -1)
        return dp[row][col];

    int left = helper(grid, row, col - 1, dp) + grid[row][col];
    int up = helper(grid, row - 1, col, dp) + grid[row][col];
    return dp[row][col] = min(left, up);
}

int minPathSum(vector<vector<int>> &grid)
{
    int row = grid.size() - 1;
    int col = grid[0].size() - 1;
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, -1));
    return helper(grid, row, col, dp);
}
int main()
{
    // vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
    cout << minPathSum(grid) << endl;
    return 0;
}