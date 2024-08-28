//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int N, long long int k)
{

    int l = 0;
    int r = 0;
    deque<long long> dq;
    vector<long long> ans;
    while (r < N)
    {
        if (arr[r] < 0)
            dq.push_back(arr[r]);

        // main sliding window.....
        if (r - l + 1 < k)
            r++;
        else if (r - l + 1 == k)
        {

            if (dq.size() == 0)
                ans.push_back(0);
            else
                ans.push_back(dq.front());

            // check for procedding further....
            if (arr[l] == dq.front())
                dq.pop_front();
            l++;
            r++;
        }
    }
    return ans;
}