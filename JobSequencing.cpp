#include <bits/stdc++.h>
using namespace std;
bool compare(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}

void JobScheduling(vector<vector<int>> arr, int n)
{   
    
     sort(arr.begin(), arr.end(), compare);
     int profit=arr[0][2];
     for(int i=1;i<n;i++)
     {
        if(arr[i][1]==arr[i-1][1])
            profit=max(profit,arr[i][2]);
        else
            profit+=max(profit,arr[i][2]);
     }
    cout<<profit;
}

int main()
{
    vector<vector<int>> jobs = {
        {1, 4, 20},
        {2, 1, 1},
        {3, 1, 40},
        {4, 1, 30}};
    sort(jobs.begin(), jobs.end(), compare);

    // Print the sorted jobs to verify
    for (const auto &job : jobs)
    {
        cout << "{" << job[0] << ", " << job[1] << ", " << job[2] << "}" << endl;
    }

    cout<<"Progit";
    JobScheduling(jobs,jobs.size());
}