class Solution {

    Boolean calculate(int[] nums, int divisor, int threshold) {
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            ans += (int) Math.ceil((double) nums[i] / (double) divisor);
        }
        return ans <= threshold;
    }

    public int smallestDivisor(int[] nums, int threshold) {
        int low = 1;
        int high = Arrays.stream(nums).max().getAsInt();
        int ans = high;
        while (low <= high) {
            int mid = (low + high)>>1;
            if (calculate(nums, mid, threshold)) {
                ans = mid; 
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
}