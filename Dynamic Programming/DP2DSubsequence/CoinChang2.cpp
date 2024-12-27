#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &coins, int ind, int amount, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (amount % coins[0] == 0)
            return 1;
        return 0;
    }
    if (dp[ind][amount] != -1)
        return dp[ind][amount];
    int notPick = helper(coins, ind - 1, amount, dp);
    int pick = 0;
    if (coins[ind] <= amount)
        pick = helper(coins, ind, amount - coins[ind], dp);
    return dp[ind][amount] = pick + notPick;
}

int change(int amount, vector<int> &coins)
{
    int n = coins.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    return helper(coins, n, amount, dp);
}
int main()
{

    vector<int> coins = {1, 2, 5};
    // vector<int> coins = {5};
    int amount = 5;
    cout << change(amount, coins);
    return 0;
}