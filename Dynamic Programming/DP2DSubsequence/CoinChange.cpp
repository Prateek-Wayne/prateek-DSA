#include <bits/stdc++.h>
using namespace std;

// int helper(vector<int> &coins, int ind, int amount)
// {
//     if (amount < 0)
//         return 0;
//     if (amount == 0)
//         return 1;
//     if (ind == 0)
//     {
//         return coins[ind] == amount;
//     }
//     int notPick = helper(coins, ind - 1, amount);

//     int pick = 0;
//     if (coins[ind] <= amount)
//     {
//         pick = helper(coins, ind - 1, amount - coins[ind]);
//     }
//     int pickRepeatedly = 0;
//     if (coins[ind] <= amount)
//     {
//         pickRepeatedly = helper(coins, ind, amount - coins[ind]);
//     }
//     return notPick + pick + pickRepeatedly;
// }

int helper(vector<int> &coins, int ind, int amount, vector<vector<int>> &dp)
{

    if (ind == 0)
    {
        if (amount % coins[ind] == 0)
        {
            return amount / coins[ind];
        }
        return 1e9;
    }
    if (dp[ind][amount] != -1)
        return dp[ind][amount];
    int notPick = helper(coins, ind - 1, amount, dp);
    int pick = INT_MAX;
    if (coins[ind] <= amount)
    {
        pick = 1 + helper(coins, ind, amount - coins[ind], dp);
    }
    return dp[ind][amount] = min(pick, notPick);
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    return helper(coins, n, amount, dp);
}
int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << coinChange(coins, amount);
    return 0;
}