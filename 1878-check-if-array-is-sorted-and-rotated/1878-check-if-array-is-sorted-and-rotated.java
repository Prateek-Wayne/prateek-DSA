class Solution {
    public boolean check(int[] nums) {
        int count = 0;
        int n = nums.length;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1])
                count++;
        }
        // also check with last one and first one
        if (nums[0] < nums[n - 1])
            count++;

        return count <= 1;
    }
}