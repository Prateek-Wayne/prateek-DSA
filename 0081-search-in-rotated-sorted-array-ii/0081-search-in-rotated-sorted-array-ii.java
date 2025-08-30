class Solution {
    public boolean search(int[] nums, int target) {
        int low = 0;
        int high = nums.length-1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (nums[mid] == target)
                return true;
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low = low + 1;
                high = high - 1;
                continue;
            }
            if (nums[low] <= nums[mid]) {

                if (nums[low] <= target && nums[mid] > target)// left is sorted
                {
                    high = mid - 1;
                } else
                    low = mid + 1;
            } else { // right is sorted
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else
                    high = mid - 1;
            }
        }
        return false;
    }
}