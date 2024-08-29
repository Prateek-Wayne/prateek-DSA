#include <bits/stdc++.h>
using namespace std;

int maxMeetings(int n, int start[], int end[]) {
    vector<pair<int, int>> arr;
    for(int i = 0; i < n; i++) {
        arr.push_back({start[i], end[i]});
    }

    sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int count = 1;
    int curr = arr[0].second;
    for(int i = 1; i < n; i++) {
        if(curr < arr[i].first) {
            count++;
            curr = arr[i].second;
        }
    }
    return count;
}

int main() {
    int n = 6;
    int start_time[] = {1, 3, 0, 5, 8, 5};
    int end_times[] = {2, 4, 6, 7, 9, 9};

    cout << maxMeetings(n, start_time, end_times);
    return 0;
}