class Solution {
    public int numOfSubarrays(int[] nums, int k, int threshold) {
        int n = nums.length;
        double sum = 0;
        int i = 0;
        int j = 0;
        int count = 0;
        while (j < n) {
            sum += nums[j];
            if (j - i + 1 == k) {
                if (sum / k >= threshold) {
                    count++;
                }
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return count;
    }
}