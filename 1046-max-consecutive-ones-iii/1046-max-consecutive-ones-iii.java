class Solution {
    public int longestOnes(int[] nums, int k) {
        int i = 0;
        int j = 0;
        int count = 0;
        int ans = 0;
        while (j < nums.length) {
            if (nums[j] == 0) {
                count++;
            }
            if (count <= k) {
                ans = Math.max(ans, j - i + 1);
            } else if (count > k) {
                while (count > k) {
                    if (nums[i] == 0)
                        count--;
                    i++;
                }
                if (count == k) {
                    ans = Math.max(j - i + 1, ans);
                }
            }
            j++;
        }
        return ans;
    }
}