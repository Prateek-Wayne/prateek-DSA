class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        int maxy = 0;
        int i = 0, j = 0, n = nums.size();
        int num = 0;
        while (j < n) {
            if ((num & nums[j]) == 0) {
                num |= nums[j];
                maxy = max(maxy, j - i + 1);
                j++;
            } else {
                num ^= nums[i];
                i++;
            }
        }

        return maxy;
    }
};