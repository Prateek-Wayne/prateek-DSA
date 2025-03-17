class Solution {
public:
    int helper(vector<int>& nums, int n, vector<int>& dp) {
        if (n == 0)
            return nums[0];
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int left = helper(nums, n - 1, dp) + 0;
        int right = helper(nums, n - 2, dp) + nums[n];
        return dp[n] = max(left, right);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return helper(nums, n - 1, dp);
    }
};