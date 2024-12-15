#include<bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& obstacleGrid,int R,int C)
{
    if(R==obstacleGrid.size()-1 && C==obstacleGrid[0].size()-1 && obstacleGrid[R][C]!=1)
    {
        return 1;
    }
    int path=0;
    if(R+1<obstacleGrid.size())
    {   
        if(obstacleGrid[R][C]!=1)
            path+=helper(obstacleGrid,R+1,C);
    }
    if(C+1<obstacleGrid[0].size())
    {
        if(obstacleGrid[R][C]!=1)
            path+=helper(obstacleGrid,R,C+1);
    }
    return path;

}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int R=0;
    int C=0;
        return helper(obstacleGrid,R,C);
    }

int main()
{
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    // vector<vector<int>> obstacleGrid =  {{0,0},{0,1}};
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;
 return 0;
}