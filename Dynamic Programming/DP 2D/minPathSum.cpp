#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &grid,int R,int C)
{
    if(R==grid.size()-1 && C==grid[0].size()-1)
    {
        return grid[R][C];
    }

    // 
    int left=INT_MAX;
    if(R<grid.size()-1)
    {
        left=helper(grid,R+1,C)+grid[R][C];
    }
    int right=INT_MAX;
    if(C<grid[0].size()-1)
    {
        right=helper(grid,R,C+1)+grid[R][C];
    }
    return min(left,right);
}

int minPathSum(vector<vector<int>> &grid)
{
    int R=0;
    int C=0;
    return helper(grid,R,C);
}
int main()
{
    // vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
    cout << minPathSum(grid) << endl;
    return 0;
}