class Solution {
 Map<String, Integer> dp;

    int helper(int[] nums, int index, int target) {
        int n = nums.length;

        if (index == n) {
            if (target == 0)
                return 1;
            return 0;
        }
        String key = index + "|" + target;
        if (dp.containsKey(key))
            return dp.get(key);
        // pick,,,
        int pick = helper(nums, index + 1, target - nums[index]);
        // not pick...
        int notPick = helper(nums, index + 1, target + nums[index]);
        dp.put(key, pick + notPick);
        return pick + notPick;
    }

    public int findTargetSumWays(int[] nums, int target) {

        int n = nums.length;
        dp = new HashMap<>();
        return helper(nums, 0, target);
    }
}