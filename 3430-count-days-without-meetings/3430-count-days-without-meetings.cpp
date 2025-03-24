class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<vector<int>> ans;
        for (int i = 0; i < meetings.size(); i++) {
            if (ans.empty() || ans.back()[1] < meetings[i][0])
                ans.push_back(meetings[i]);
            else {
                ans.back()[1] = max(ans.back()[1], meetings[i][1]);
            }
        }
        int counter = 0;
        counter += ans[0][0] - 1;
        for (int i = 1; i < ans.size(); i++) {
            counter += ans[i][0] - ans[i - 1][1] - 1;
        }
        counter += days - ans.back()[1] ;
        return counter;
    }
};