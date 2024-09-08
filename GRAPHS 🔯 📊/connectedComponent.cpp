#include <bits/stdc++.h>
using namespace std;

void BFS(vector<int> adj[], vector<int> &Visited, int Node)
{
    queue<int> q;
    q.push(Node);
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        for (auto i : adj[it])
        {
            if (Visited[i] == 0)
            {
                Visited[i] = 1;
                q.push(i);
            }
        }
    }
}
void solve(int A, vector<vector<int>> &B)
{
    vector<int> adj[A];
    int count=0;

    for (auto i : B)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<int> Visited(A,0);
    for(int i=0;i<adj->size();i++)
    {
        if(Visited[i]==0)
        {
            count++;
            BFS(adj,Visited,i);
        }
    }
    cout<<count;
}
int main()
{
    int A = 4;
    vector<vector<int>> B = {{1, 2}, {2, 3}};
    solve(A, B);
}