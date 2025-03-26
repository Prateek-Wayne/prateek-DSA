class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> ans;
        for (auto i : grid) {
            for (auto x : i)
                ans.push_back(x);
        }
         sort(ans.begin(), ans.end());
        int firstModulo = ans[0] % x;
        for (auto i : ans) {
            if (i % x != firstModulo)
                return -1;
        }
        int counter = 0;
        int target = ans.size() / 2;
        for (auto i : ans) {
            counter += abs(i - ans[target]) / x;
        }
        return counter;
    }
};