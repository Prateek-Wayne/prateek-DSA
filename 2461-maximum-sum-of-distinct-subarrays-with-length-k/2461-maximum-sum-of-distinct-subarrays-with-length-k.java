class Solution {
 public long maximumSubarraySum(int[] nums, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int i = 0, j = 0;
        long sum = 0;
        long ans = 0;
        while (j < nums.length) {
            sum += nums[j];
            mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);
            if (j - i + 1 == k) {
                if (mp.size() == k) {
                    ans = Math.max(ans, sum);
                }
                mp.put(nums[i], mp.get(nums[i]) - 1);
                sum-=nums[i];
                if (mp.get(nums[i]) == 0)
                    mp.remove(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
}