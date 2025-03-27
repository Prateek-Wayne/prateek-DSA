class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for (auto i : nums)
            mp[i]++;
        int element = -1;
        int count = -1;
        for (auto i : mp) {
            if (i.second > count) {
                count = i.second;
                element = i.first;
            }
        }
        if (count > n) {
            return -1;
        }
        int dominating = 0;
        int i = 0;
        for (i; i < n; i++) {
            if (nums[i] == element) {
                dominating++;
            }
            if (dominating > (i + 1) / 2)
                break;
        }
        if ((count - dominating) > ((n - i-1) / 2))
            return i;
        return -1;
    }
};