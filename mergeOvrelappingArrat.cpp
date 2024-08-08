#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &arr)
{   
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0;i<arr.size();i++)
    {
        if(!ans.empty() && arr[i][0]<=ans.back()[1])
        {
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
        else{
            ans.push_back(arr[i]);
        }
    }
    return ans;
   
    

}

int main()
{   
    // vector<vector<int>> array = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};
    // vector<vector<int>> array = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // vector<vector<int>> array = {{1,4},{4,5}};
    vector<vector<int>> array = {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};

    vector<vector<int>> ans = merge(array);

    // Loop to print the 2D array
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}