//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
    int curr_sum=0;
    int ans=0;
    map<int,int> mp;
    mp[0]=-1;
    for(int i=0;i<n;i++)
    {
        if(mp.find(curr_sum+arr[i])!=mp.end())
        {
            auto iter=mp.find(curr_sum+arr[i]);
            ans=max(ans,i-iter->second);
            curr_sum+=arr[i];
        }
        else{
            curr_sum+=arr[i];
            mp[curr_sum]=i;
        }
    }
    return ans;

}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends