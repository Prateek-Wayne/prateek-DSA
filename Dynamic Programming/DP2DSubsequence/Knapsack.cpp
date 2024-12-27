#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &val, vector<int> &wt, int ind, int W, vector<vector<int>> &dp)
{
    // base
    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        return 0;
    }
    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notPick = helper(val, wt, ind - 1, W, dp) + 0;
    int pick = INT_MIN;
    if (wt[ind] <= W)
    {
        pick = val[ind] + helper(val, wt, ind - 1, W - wt[ind], dp);
    }
    return dp[ind][W] = max(pick, notPick);
}

int knapSack(int capacity, vector<int> &val, vector<int> &wt)
{
    // code here
    int n = val.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 0; i <= capacity; i++)
    {
        if (wt[0] <= i)
            dp[0][i] = val[0];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            // int notPick = helper(val, wt, ind - 1, W, dp) + 0;
            int notPick = dp[i - 1][j] + 0;
            int pick = INT_MIN;
            // if (wt[ind] <= W)
            // {
            //     pick = val[ind] + helper(val, wt, ind - 1, W - wt[ind], dp);
            // }
            if (wt[i] <= j)
            {
                pick = val[i] + dp[i - 1][j - wt[i]];
            }
            dp[i][j] = max(pick, notPick);
        }
    }

    return dp[n][capacity];
}
int main()
{
    //  capacity = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
    int capacity = 7;
    vector<int> val = {10, 8, 6};
    vector<int> wt = {1, 7, 9};

    cout << knapSack(capacity, val, wt) << endl;
    return 0;
}