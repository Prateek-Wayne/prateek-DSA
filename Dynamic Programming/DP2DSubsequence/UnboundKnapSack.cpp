#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &val, vector<int> &wt, int ind, int W, vector<vector<int>> &dp)
{
    // base
    if (ind == 0)
    {
        if (wt[0] <= W)
            return (W / wt[0]) * val[0];
        return 0;
    }
    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notPick = helper(val, wt, ind - 1, W, dp);
    int pick = INT_MIN;
    if (wt[ind] <= W)
        pick = val[ind] + helper(val, wt, ind, W - wt[ind], dp);
    return dp[ind][W] = max(pick, notPick);
}

int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = wt.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 0; i <= capacity; i++)
    {
        if (wt[0] <= i)
            dp[0][i] = (i / wt[0]) * val[0];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            // int notPick = helper(val, wt, ind - 1, W, dp);
            int notPick = 0 + dp[i - 1][j];
            int pick = INT_MIN;

            // if (wt[ind] <= W)
            //     pick = val[ind] + helper(val, wt, ind, W - wt[ind], dp);
            if (wt[i] <= j)
                pick = val[i] + dp[i][j - wt[i]];
            dp[i][j] = max(pick, notPick);
        }
    }
    return dp[n][capacity];
}
int main()
{
    // vector<int> val = {6, 1, 7, 7};
    vector<int> val = {1, 1};
    // vector<int> wt = {1, 3, 4, 5};
    vector<int> wt = {2, 1};
    int capacity = 3;
    cout << knapSack(val, wt, capacity);
    return 0;
}