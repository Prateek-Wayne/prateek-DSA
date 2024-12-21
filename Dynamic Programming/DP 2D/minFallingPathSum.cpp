#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp)
{

    if (col < 0 || col >= matrix[0].size())
        return INT_MAX - 10000;
    if (row == 0)
        return dp[row][col] = matrix[row][col];

    if (dp[row][col] != -1)
        return dp[row][col];
    int up = helper(matrix, row - 1, col, dp) + matrix[row][col];
    int upper_l = helper(matrix, row - 1, col - 1, dp) + matrix[row][col];
    int upper_r = helper(matrix, row - 1, col + 1, dp) + matrix[row][col];
    return dp[row][col] = min(up, min(upper_l, upper_r));
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int row = matrix.size() - 1;
    int col = matrix[0].size() - 1;
    int ans = INT_MAX;
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, -1));
    for (int i = 0; i <= col; i++)
    {
        ans = min(ans, helper(matrix, row, i, dp));
    }
    return ans;
}
int main()
{
    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << minFallingPathSum(matrix) << endl;
    return 0;
}

vector<vector<long long>> solve(int Q,vector<long long> Query)
{

}