class Solution {
public:
    int mergeIntervals(vector<vector<int>> arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            if (ans.empty() || ans.back()[1] <= arr[i][0]) {
                ans.push_back(arr[i]);
            } else {

                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }
        return ans.size();
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x;
        vector<vector<int>> y;
        for (auto i : rectangles) {
            x.push_back({i[0], i[2]});
            y.push_back({i[1], i[3]});
        }
        if (mergeIntervals(x) > 2 || mergeIntervals(y) > 2)
            return true;
        return false;
    }
};