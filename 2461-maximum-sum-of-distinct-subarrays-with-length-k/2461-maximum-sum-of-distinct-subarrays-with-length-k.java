class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
          int n = nums.length;
        HashMap<Integer, Integer> mp = new HashMap<>();
        int i = 0;
        int j = 0;
        long sum = 0;
        long maxy = 0;
        while (j < n) {
            sum += nums[j];
            mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);
            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k) {
                if (mp.size() == k) {
                    maxy = Math.max(maxy, sum);
                }
                sum -= nums[i];
                if (mp.containsKey(nums[i])) {
                    mp.put(nums[i], mp.get(nums[i]) - 1);
                    if (mp.get(nums[i]) == 0) {
                        mp.remove(nums[i]);
                    }
                }
                i++;
                j++;
            }
        }
        return maxy;
    }
}