#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &arr,int last,int days)
{   // base...
    if(days==0)
    {
        int temp=INT_MIN;
        for(int i=0;i<arr[0].size();i++)
        {

            if(i!=last)
                temp=max(temp,arr[days][i]);
        }
        return temp;
    }
    int ans=INT_MIN;
    for(int i=0;i<arr[0].size();i++)
    {   
        if(i!=last)
        {
            int temp=helper(arr,i,days-1)+arr[days][i];
            ans=max(ans,temp);
        }
    }
    return ans;

}

int maximumPoints(vector<vector<int>> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(arr[0].size(), -1));
    return helper(arr,3,n-1,dp);
}
int main()
{   

        // Input: n=3 and arr[]= [[1,2,5],[3,1,1],[3,3,3]]
        // vector<vector<int>> arr = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
        // 2,1,6| 3,4,6  | 10,1,6 | 8,3,7
        vector<vector<int>> arr = {{2, 1, 3}, {3, 4, 6}, {10, 1, 6}, {8, 3, 7}};
        int n = 4;
        cout << maximumPoints(arr, n) << endl;

    return 0;
}