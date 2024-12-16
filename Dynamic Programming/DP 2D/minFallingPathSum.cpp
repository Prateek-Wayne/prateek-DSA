#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &matrix, int R, int C)
{
    if (R == matrix.size() - 1)
    {
        return matrix[R][C];
    }
    int dr;

    if (C < matrix.size())
    {
        dr = helper(matrix, R + 1, C + 1) + matrix[R][C];
    }
    int dl;
    if (C > 0)
    {
        dl = helper(matrix, R + 1, C - 1) + matrix[R][C];
    }
    int down = helper(matrix, R + 1, C) + matrix[R][C];

    return min(down, min(dl, dr));
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int ans = INT_MAX;
    for (int i = 0; i < matrix.size(); i++)
    {
        ans = min(ans, helper(matrix, 0, i));
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << minFallingPathSum(matrix) << endl;
    return 0;
}