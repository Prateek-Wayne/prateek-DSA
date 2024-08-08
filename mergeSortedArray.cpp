#include<bits/stdc++.h>
using namespace std;

void merge(vector<long long>& arr1, vector<long long>& arr2, int n, int m) {
    int p1 = n - 1;
    int p2 = 0;
    for (int i = 0; i < min(n, m); i++) {
        if (arr1[p1] > arr2[p2]) {
            swap(arr1[p1], arr2[p2]);
            p1--;
            p2++;
        }
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
     cout << "Merged array 1: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Merged array 2: ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 4;
    int m = 5;
    vector<long long> arr1 = {1, 3, 5, 7};
    vector<long long> arr2 = {0, 2, 6, 8, 9};
    merge(arr1, arr2, n, m);
   
}
