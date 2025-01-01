class Solution {
public:
    int helper(vector<int>& prices, int ind, int b, vector<vector<int>> & dp) {
        if (ind == prices.size())
            return 0;
        if (dp[ind][b] != -1)
            return dp[ind][b];

        if (!b) {
            return dp[ind][b] =
                       max(-prices[ind] + helper(prices, ind + 1, 1, dp),
                           0 + helper(prices, ind + 1, 0, dp));
        } else {
            return dp[ind][b] =
                       max(+prices[ind] + helper(prices, ind + 1, 0, dp),
                           0 + helper(prices, ind + 1, 1, dp));
        }
    }

    int maxProfit(vector<int>& prices)

    {
        int n = prices.size() - 1;
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return helper(prices, 0, 0, dp);
    }
};