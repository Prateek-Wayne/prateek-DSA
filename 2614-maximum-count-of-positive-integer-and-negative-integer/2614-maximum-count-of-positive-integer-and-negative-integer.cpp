class Solution {
public:
    int binarySearchNeg(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < 0)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
    int binarySearchPos(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > 0)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
    int maximumCount(vector<int>& nums) {
        int pos = nums.size() - binarySearchPos(nums);
        int neg = binarySearchNeg(nums);
        return max(pos, neg);
    }
};