//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        int low = 1, high = m;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int power = pow(mid, n);
        if (power == m)
            return mid;
        else if (power < m)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends