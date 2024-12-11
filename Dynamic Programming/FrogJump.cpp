#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &height, int n, vector<int> &dp) // n is 0 based n-1...
{
    if (n == 0)
    {
        dp[0] = 0;
        return 0;
    }
    if (dp[n] != -1)
        return dp[n];
    int left = helper(height, n - 1, dp) + abs(height[n] - height[n - 1]);
    int right = INT_MAX;
    if (n > 1)
    {
        right = helper(height, n - 2, dp) + abs(height[n] - height[n - 2]);
    }
    return dp[n] = min(left, right);
}

int minimumEnergy(vector<int> &height, int n)
{
    // Code here
    vector<int> dp(n + 1, -1);
    return helper(height, n - 1, dp);
}

int main()
{
    vector<int> height = {10, 20, 30, 10};
    int n = 4;
    cout << minimumEnergy(height, n);
    return 0;
}