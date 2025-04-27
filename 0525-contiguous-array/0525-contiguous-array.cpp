class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> mp;
        mp[0] = -1;
        int ans = 0;
        int prefixSum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                nums[i] = -1;
        }
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            if (mp.count(prefixSum)) {
                ans = max(ans, i - mp[prefixSum]);
                mp[prefixSum] = min(mp[prefixSum], i);
            } else
                mp[prefixSum] = i;
        }
        return ans;
    }
};