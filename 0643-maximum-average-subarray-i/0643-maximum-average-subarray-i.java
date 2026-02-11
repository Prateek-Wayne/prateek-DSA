class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int n = nums.length;
        double sum = 0;
        double ans = Integer.MIN_VALUE;
        int i = 0;
        int j = 0;
        while (j < n) {
            sum += nums[j];
            if (j - i + 1 == k) {
                ans = Math.max(ans, sum / (double) k);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
}