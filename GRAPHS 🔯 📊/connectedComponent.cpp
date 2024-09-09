#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> &adj, vector<int> &Visited, int Node)
{
    queue<int> q;
    q.push(Node);
    Visited[Node] = 1;

    while (!q.empty())
    {
        int it = q.front();
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
    vector<vector<int>> adj(A); // Correctly initialize the adjacency list
    int count = 0;

    // Build the adjacency list
    for (auto i : B)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    vector<int> Visited(A, 0); // Initialize visited array to 0

    for (int i = 0; i < A; i++)
    {
        if (Visited[i] == 0)
        {
            count++;
            BFS(adj, Visited, i);
        }
    }

    cout << count << endl;
}

int main() {
    int A = 100;
    vector<vector<int>> B = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}}; // Example input
    solve(A, B);

    return 0;
}
