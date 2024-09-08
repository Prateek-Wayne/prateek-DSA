#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges)
{
    // Code here
    vector<vector<int>> ans(V);
    for(auto i:edges)
    {
        ans[i.first].push_back(i.second);
        ans[i.second].push_back(i.first);
    }
    return ans;
}

int main()
{
}