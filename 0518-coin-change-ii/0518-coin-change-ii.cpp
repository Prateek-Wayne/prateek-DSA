class Solution {
public:
    int helper(vector<int>& coins, int index, int amount,
               vector<vector<int>>& dp) {
        if (index == 0) {
            if (amount % coins[index] == 0)
                return 1;
            return 0;
        }
        if (dp[index][amount] != -1)
            return dp[index][amount];
        // not pick
        int notPick = helper(coins, index - 1, amount, dp);
        int pick = 0;
        if (coins[index] <= amount) {
            pick = helper(coins, index, amount - coins[index], dp);
        }
        return dp[index][amount] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return helper(coins, n - 1, amount, dp);
    }
};