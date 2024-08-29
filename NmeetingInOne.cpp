#include <bits/stdc++.h>
using namespace std;

int maxMeetings(int n, int start[], int end[])
{
    // Your code here
    vector<vector<int>> arr;
    for(int i=0;i<n;i++)
    {
        arr.push_back({start[i],end[i]});
    }

    sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    int count = 1;
    int curr = arr[0][1];
    for(int i=0;i<n;i++)
    {
        if(curr<arr[i+1][0])
        {
            count++;
            curr=end[i+1];
        }
    }
    return count;

}
int main()
{
int n=6;
int start_time[] = {1, 3, 0, 5, 8, 5};
int end_times[] = {2, 4, 6, 7, 9, 9};

cout<<maxMeetings(n,start_time,end_times);


}