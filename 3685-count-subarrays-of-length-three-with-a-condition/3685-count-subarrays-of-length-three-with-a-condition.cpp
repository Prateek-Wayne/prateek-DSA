class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            float first = nums[i];
            float second = nums[i + 1];
            float third = nums[i + 2];
            if (first + third == second / 2)
                count++;
        }
        return count;
    }
};