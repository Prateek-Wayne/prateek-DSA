class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int i = 0;
        int j = 0;
        for (int n : nums) {
            if (n < pivot)
                i++;
            if (n == pivot)
                j++;
        }
        int k = i + j;
        j = i;
        i = 0;
        int[] ans = new int[nums.length];
        for (int x = 0; x < nums.length; x++) {
            if (nums[x] < pivot) {
                ans[i] = nums[x];
                i++;
            } else if (nums[x] == pivot) {
                ans[j] = nums[x];
                j++;
            } else {
                ans[k] = nums[x];
                k++;
            }
        }
        return ans;
    }
}