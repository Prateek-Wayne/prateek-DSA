class Solution {
public:
int helper(vector<int> &prices, int ind, int buy, vector<vector<int>> &dp)
{
    int n = prices.size();
    if (ind == n)
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[ind] + helper(prices, ind + 1, 0, dp),
                     0 + helper(prices, ind + 1, 1, dp));
    }
    else
    {
        profit = max(prices[ind] + helper(prices, ind + 1, 1, dp), 0 + helper(prices, ind + 1, 0, dp));
    }
    return dp[ind][buy] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return helper(prices, 0, 1, dp);
}
};