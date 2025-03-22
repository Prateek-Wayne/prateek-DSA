class Solution {
public:

int helper(vector<int> &nums, int target, int index)
{
   if (index == 0)
    {
        if (target == nums[0] && target == -nums[0])
            return 2;
        if (target == nums[0] || target == -nums[0])
            return 1;
        return 0;
    }

    // plus
    int left = helper(nums, target - nums[index], index - 1);
    // minus
    int right = helper(nums, target + (nums[index]), index - 1);
    return left + right;
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    
    return helper(nums, target, n - 1);
}
};