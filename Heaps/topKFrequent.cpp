#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
vector<int> topKFrequent(vector<int> &nums, int k)
{
    map<int,int> mp;
    vector<int> ans;
    for(int i=0;i<nums.size();i++)
    {
        mp[nums[i]]++;
    }
    priority_queue<ii,vector<ii>,greater<ii > >q;

    for(auto i:mp)
    {
        q.push({i.second,i.first});
        if(q.size()>k)
            q.pop();
    }
    while(!q.empty())
    {   
        // auto it=
        ans.push_back(q.top().second);
        q.pop();
    }
    return ans;



}

 vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // priority_queue< ii,vector<ii> , greater <ii>> q;// {distance,index}
        priority_queue<ii> q;
        for(int i=0;i<points.size();i++)
        {
            int distance=sqrt((points[i][0]*points[i][0])+(points[i][1]*points[i][1]));
            q.push({distance,i});
            if(q.size()>k)
                q.pop();
            
        }
        vector<vector<int>> ans;
        while(!q.empty())
        {
            ans.push_back(points[q.top().second]);
            q.pop();
        }
        return ans;
        
    }

int largest(vector<int> &arr) {
        // code here
        priority_queue< int,vector<int> ,greater<int>> q;
        for(int i=0;i<arr.size();i++)
        {
            q.push(arr[i]);
            if(q.size()>2)
                q.pop();
        }
        return q.top();
    }

int main()
{
}