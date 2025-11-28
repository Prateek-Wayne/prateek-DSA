class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mp = new HashMap<>();
        mp.put(nums[0], 0);
        for (int i = 1; i < nums.length; i++) {
            int r = target - nums[i];
            if (mp.containsKey(r)) {
                return new int[] { mp.get(r), i };
            }
            mp.put(nums[i], i);
        }
        return new int[] { -1, -1 };
    }
}