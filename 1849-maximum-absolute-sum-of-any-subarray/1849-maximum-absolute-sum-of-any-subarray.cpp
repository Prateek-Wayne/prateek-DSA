class Solution {
public:
    int kedanesAlgo(vector<int>& nums) {
        int sum = 0, maxy = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxy = max(maxy, sum);
            if (sum < 0)
                sum = 0;
        }
        return maxy;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        int max1 = kedanesAlgo(nums);
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = (-1) * nums[i];
        }
        int max2 = kedanesAlgo(nums);
        return max(max2, max1);
    }
};