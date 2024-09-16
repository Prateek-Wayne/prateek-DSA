
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> p;

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    priority_queue<p> q;
    vector<int> ans;
    for(int i=0;i<arr.size();i++)
    {
        q.push({abs(arr[i]-x),arr[i]});
        if(q.size()>k)
        {
            q.pop();
        }
    }
    while(!q.empty())
    {
        ans.push_back(q.top().second);
        q.pop();
    }
    return ans;
}

int main()
{
}