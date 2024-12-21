#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &triangle, int row, int col)
{
    if (row < 0 || col < 0 || col > row)
        return INT_MAX - 1000;
    if (row == 0 && col == 0)
        return triangle[row][col];

    int left = helper(triangle, row - 1, col - 1) + triangle[row][col];
    int up = helper(triangle, row, col - 1) + triangle[row][col];

    return min(left, up);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int row = triangle.size() - 1;
    int col = triangle[row].size() - 1;
    int ans = INT_MAX;
    for (int i = 0; i <= col; i++)
    {
        ans = min(ans, helper(triangle, row, i));
    }
    return ans;
}
int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    cout << minimumTotal(triangle) << endl;
    return 0;
}