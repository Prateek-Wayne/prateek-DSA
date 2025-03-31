class Solution {
public:
int helper(vector<int> &prices, int ind, int buy, int count, vector<vector<vector<int>>> &dp,int k)
{
    int n = prices.size();
    if (count == k || ind == n)
        return 0;
    // buy...
    if (dp[ind][buy][count] != -1)
        return dp[ind][buy][count];
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[ind] + helper(prices, ind + 1, 0, count, dp,k),
                     helper(prices, ind + 1, buy, count, dp,k));
    }
    else
    {
        profit = max(prices[ind] + helper(prices, ind + 1, 1, count + 1, dp,k),
                     helper(prices, ind + 1, 0, count, dp,k));
    }
    return dp[ind][buy][count] = profit;
}

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
    return helper(prices, 0, 1, 0, dp,k);
}
};