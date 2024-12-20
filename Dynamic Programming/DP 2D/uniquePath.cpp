#include <bits/stdc++.h>
using namespace std;

int helper(int row, int col, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
        return 1;
    if (row < 0 || col < 0)
        return 0;

    if (dp[row][col] != -1)
        return dp[row][col];

    int left = helper(row, col - 1, dp);
    int right = helper(row - 1, col, dp);

    return dp[row][col] = left + right;
}

int uniquePaths(int m, int n)
{
    int row = m - 1;
    int col = n - 1;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(row, col, dp);
}

int main()
{
    cout << uniquePaths(3, 2);
    return 0;
}