#include <bits/stdc++.h>
using namespace std;

class Data {
public:
    int value;
    int row;
    int col;
    Data(int v, int r, int c) {
        value = v;
        row = r;
        col = c;
    }
};

// Custom comparator for min-heap
struct CompareData {
    bool operator()(Data const& d1, Data const& d2) {
        return d1.value > d2.value; // Min-heap: smallest element at the top
    }
};

vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    priority_queue<Data, vector<Data>, CompareData> q;
    vector<int> ans;

    for (int i = 0; i < K; i++) {
        Data data(arr[i][0], i, 0);
        q.push(data);
    }
    while (!q.empty()) {
        auto it = q.top();
        q.pop();
        ans.push_back(it.value);
        int r = it.row;
        int c = it.col + 1;
        if (c < arr[r].size()) {
            Data data(arr[r][c], r, c);
            q.push(data);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    mergeKArrays(arr, arr.size());
}
