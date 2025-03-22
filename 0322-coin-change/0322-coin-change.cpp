class Solution {
public:

int helper(vector<int> &coins, int index, int &amount, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (amount % coins[0] == 0)
            return amount / coins[0];
        return 1e7;
    }
    // notPick
    if (dp[index][amount] != -1)
        return dp[index][amount];
    int notPick = 0 + helper(coins, index - 1, amount, dp);
    int pick = INT_MAX;
    if (coins[index] <= amount)
    {
        amount -= coins[index];
        pick = 1 + helper(coins, index, amount, dp);
        amount += coins[index];
    }
    return dp[index][amount] = min(pick, notPick);
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = helper(coins, n - 1, amount, dp);
    if (ans >= 1e7)
        return -1;
    return ans;
}
};