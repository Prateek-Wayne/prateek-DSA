#include <bits/stdc++.h>
using namespace std;

vector<int> nearlySorted(int arr[], int num, int K)
{
    priority_queue<int,vector<int>,greater<int>> q;
    vector<int> ans;
    for(int i=0;i<num;i++)
    {
        q.push(arr[i]);
        if(q.size()>K)
        {
            ans.push_back(q.top());
            q.pop();
        }
    }
    while(!q.empty())
    {
        ans.push_back(q.top());
            q.pop();
    }
    return ans;
}

int main()
{
}