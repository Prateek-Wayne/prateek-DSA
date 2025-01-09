class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxt = 0;
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    q.push({{i, j}, 0});
            }
        }
        int Drow[] = {0, 0, -1, 1};
        int Dcol[] = {-1, 1, 0, 0};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            maxt = max(maxt, t);
            for (int i = 0; i < 4; i++) {
                int newR = r + Drow[i];
                int newC = c + Dcol[i];
                if (newR < n && newR >= 0 && newC < m && newC >= 0 &&
                    grid[newR][newC] == 1) {
                    grid[newR][newC] = 2;
                    q.push({{newR, newC}, t + 1});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return maxt;
    }
};