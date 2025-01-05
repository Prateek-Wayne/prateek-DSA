#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &arr, int ind, int prev, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        int ans = INT_MIN;
        for (int i = 0; i <= 2; i++)
        {
            if (i != prev)
                ans = max(ans, arr[0][i]);
        }
        return ans;
    }
    if (dp[ind][prev] != -1)
        return dp[ind][prev];
    int ans = INT_MIN;
    for (int i = 0; i <= 2; i++)
    {
        if (i != prev)
        {
            ans = max(ans, helper(arr, ind - 1, i, dp) + arr[ind][i]);
        }
    }
    return dp[ind][prev] = ans;
}

int maximumPoints(vector<vector<int>> &arr, int n)
{

    vector<vector<int>> dp(n, vector<int>(arr[0].size() + 1, -1));
    return helper(arr, n - 1, 3, dp);
}
int main()
{
    vector<vector<int>> ans = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    cout << maximumPoints(ans, ans.size());
    return 0;
}