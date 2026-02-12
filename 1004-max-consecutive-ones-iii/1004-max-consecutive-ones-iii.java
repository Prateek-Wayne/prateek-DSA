class Solution {
    public int longestOnes(int[] nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.length;
        int count = 0;
        int ans = 0;
        while (j < n) {
            if (nums[j] == 0)
                count++;
            if (count <= k) {
                ans = Math.max(ans, j - i + 1);
            } else {
                while (count > k) {
                    if (nums[i] == 0)
                        count--;
                    i++;
                }
                if (count <= k) {
                    ans = Math.max(ans, j - i + 1);
                }
            }
            j++;
        }
        return ans;
    }
}