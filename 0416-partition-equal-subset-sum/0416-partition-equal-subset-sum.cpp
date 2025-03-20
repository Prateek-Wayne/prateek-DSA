class Solution {
public:
    bool helper(vector<int>& nums, int index, int target,
                vector<vector<int>>& dp) {
        if (target < 0)
            return false;
        if (target == 0)
            return true;
        if (index == 0) {
            if (target == 0 || nums[index] == target)
                return true;
            return false;
        }
        if (dp[index][target] != -1)
            return dp[index][target];
        //
        target -= nums[index];
        bool left = helper(nums, index - 1, target, dp);
        target += nums[index];
        bool right = helper(nums, index - 1, target, dp);
        return dp[index][target] = left || right;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return false;
        sum = sum / 2;
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return helper(nums, n - 1, sum, dp);
    }
};