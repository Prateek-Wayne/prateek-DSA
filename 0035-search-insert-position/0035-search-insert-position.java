class Solution {
    public int searchInsert(int[] nums, int target) {
        int ans = Arrays.binarySearch(nums, target);
        if (ans<0 ) {
            return ans*(-1)-1;
        }
        return ans;
    }
}