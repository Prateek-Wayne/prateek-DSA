#include <bits/stdc++.h>
using namespace std;

 int KthLargest(int arr[], int n, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<n;i++)
        {
            q.push(arr[i]);
            if(q.size()>k)
                q.pop();
        }
        return q.top();
}

int main()
{
    // priority_queue<int, vector<int>, greater<int>> q;//min heap
    priority_queue<int> q;
    vector<int> v = {3,1,4,4,5,2,6,1};
    for (int i = 0; i < v.size(); i++)
    {
        q.push(v[i]);
    }
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
}