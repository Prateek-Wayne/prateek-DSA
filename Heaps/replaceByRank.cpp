#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> pp;
vector<int> replaceWithRank(vector<int> &arr, int N)
{
    priority_queue<pp,vector<pp> ,greater<pp>> q;
    // vector<int> ans;
    for(int i=0;i<N;i++)
    {
        q.push({arr[i],i});
    }
    int count=1;
    while(!q.empty())
    {
        auto it=q.top();
        q.pop();
        arr[it.second]=count;
        count++;
    }
    return arr;


}
int main()
{
}