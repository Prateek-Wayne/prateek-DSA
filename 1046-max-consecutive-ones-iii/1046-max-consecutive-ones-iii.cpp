class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, temp = 0, ans = 0;
        int N = nums.size();
        while (j < N) {
            if (nums[j] == 0)
                temp++;
            if (temp <= k) {
                ans = max(ans, j - i + 1);
                j++;
            } else {
                while (temp > k) {
                    if (nums[i] == 0)
                        temp--;
                    i++;
                }
                if (temp == k) {
                    ans = max(ans, j - i + 1);
                }
                j++;
            }
        }
        return ans;
    }
};