class Solution {
public:
    void helper(vector<int>& candidates, vector<int>& ds, int index, int sum,
                int target, vector<vector<int>>& ans) {

        // base...
        if (index == candidates.size()) {
            if (sum == target) {
                ans.push_back(ds);
            }
            return;
        }
        // ...
        if (sum == target) {
            ans.push_back(ds);
            return;
        }

        if (sum < target) {
            ds.push_back(candidates[index]);
            helper(candidates, ds, index, sum + candidates[index], target, ans);
            ds.pop_back();
        }
        helper(candidates, ds, index + 1, sum, target, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> ds = {};
        helper(candidates, ds, 0, 0, target, ans);
        return ans;
    }
};