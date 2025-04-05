class Solution {
public:
    void helper(vector<int>& nums, int index, vector<int>& ds, int& ans) {
        if (index < 0) {
            if (ds.size() == 0) {
                ans += 0;
                return;
            }
            int temp = ds[0];
            for (int i = 1; i < ds.size(); i++) {
                temp = temp ^ ds[i];
            }
            ans += temp;
            return;
        }
        // pick..
        ds.push_back(nums[index]);
        helper(nums, index - 1, ds, ans);
        // no pick
        ds.pop_back();
        helper(nums, index - 1, ds, ans);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> ds = {};
        helper(nums, n - 1, ds, ans);
        return ans;
    }
};