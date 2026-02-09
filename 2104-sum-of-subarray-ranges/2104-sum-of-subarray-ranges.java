class Solution {
 public static long subArrayRanges(int[] nums) {
        long total = 0;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            int maxy = Integer.MIN_VALUE;
            int mini = Integer.MAX_VALUE;
            for (int j = i; j < n; j++) {
                maxy = Math.max(maxy, nums[j]);
                mini = Math.min(mini, nums[j]); 
                total += (maxy - mini); 
            }
        }
        return total;
    }
}