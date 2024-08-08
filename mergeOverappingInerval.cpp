#include <bits/stdc++.h>
using namespace std;

//  vector<vector<int>>
void merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {

        if (intervals[i][0] <= ans.back()[1])
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        else
        {
            ans.push_back(intervals[i]);
        }
    }
    for (auto i : ans)
    {
        cout << i[0] << "|" << i[1] << " ";
    }
}


int main()
{
    // vector<int> nums={1,1,1,2,2,2,0,0,0,2};
    // vector<vector<int>> matrix = {{1, 3},
    //                               {2, 6},
    //                               {8, 10},
    //                               {15, 18}};
    vector<vector<int>> matrix = {{1, 4},
                                  {4, 5}};

    merge(matrix);

    // cout<<endl<<matrix.back()[0];

    return 0;
}