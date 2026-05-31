class Solution {
    int lowerBound(int[] nums, int target) {
        int low = 0;
        int ans = nums.length;
        int high = nums.length - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }

    int upperBound(int[] nums, int target) {
        int low = 0;
        int ans = nums.length;
        int high = nums.length - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }

    public int[] searchRange(int[] nums, int target) {

        int n = nums.length;

        int lb = lowerBound(nums, target);

        if (lb == n || nums[lb] != target)
            return new int[] { -1, -1 };

        int ub = upperBound(nums, target);

        return new int[] { lb, ub - 1 };
    }
}