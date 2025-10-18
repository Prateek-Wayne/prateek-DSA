class Solution {
    public int maxSubarraySum(int[] arr, int k) {
        // Code here
                int sum = 0;
        int i = 0;
        int j = 0;
        int n = arr.length;
        int ans = Integer.MIN_VALUE;
        while (j < n) {
            sum += arr[j];
            if ((j - i + 1) < k) {
                // continue;
            } else if ((j - i + 1) == k) {
                ans = Math.max(sum, ans);
                sum = sum - arr[i];
                i++;
            }
            j++;
        }
        return ans;
    }
}