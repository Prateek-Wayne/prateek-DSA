#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &triangle, int R, int C)
{
    if (R == triangle.size() - 1)
    {
        return triangle[R][C];
    }

    int left=triangle[R][C]+helper(triangle,R+1,C);
    int right=triangle[R][C]+helper(triangle,R+1,C+1);
    return min(left,right);
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
    // vector<vector<int>> triangle ={{-10}};
    vector<vector<int>> triangle ={{-1},{-2,-3}};
    cout << minimumTotal(triangle) << endl;
    return 0;
}