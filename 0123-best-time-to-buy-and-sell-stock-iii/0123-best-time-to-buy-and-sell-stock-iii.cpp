class Solution {
public:
int helper(vector<int> &prices, int ind, int buy, int count, vector<vector<vector<int>>> &dp)
{
    int n = prices.size();
    if (count == 2 || ind == n)
        return 0;
    // buy...
    if (dp[ind][buy][count] != -1)
        return dp[ind][buy][count];
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[ind] + helper(prices, ind + 1, 0, count, dp),
                     helper(prices, ind + 1, buy, count, dp));
    }
    else
    {
        profit = max(prices[ind] + helper(prices, ind + 1, 1, count + 1, dp),
                     helper(prices, ind + 1, 0, count, dp));
    }
    return dp[ind][buy][count] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
    return helper(prices, 0, 1, 0, dp);
}
};