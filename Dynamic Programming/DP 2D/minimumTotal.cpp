#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &triangle, int R, int C)
{
    if (R == triangle.size() - 1)
    {
        return triangle[R][C];
    }

    int left = INT_MAX;
    int right = INT_MAX;
    if (R < triangle.size() - 1)
    {

        left = helper(triangle, R + 1, C) + triangle[R][C];

        if (R < triangle.size() - 1 && C + 1 < triangle[R].size() - 1)
        {
            right = helper(triangle, R + 1, C + 1) + triangle[R][C];
        }
    }
    return min(left, right);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int R = 0;
    int C = 0;
    return helper(triangle, R, C);
}
int main()
{
    // vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    vector<vector<int>> triangle ={{-10}};
    cout << minimumTotal(triangle) << endl;
    return 0;
}