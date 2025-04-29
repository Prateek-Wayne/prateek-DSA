class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        int low = 0, high = 0;
        int n = nums.size();

        int maxy = INT_MIN;
        for (auto i : nums) {
            maxy = max(maxy, i);
        }
        long long count = 0, ans = 0;
        while (high < n) {
            if (nums[high] == maxy) {
                count++;
            }
            while (count == k) {
                ans += n - high;
                if (nums[low] == maxy) {
                    count--;
                }
                low++;
            }
            high++;
        }
        return ans;
    }
};