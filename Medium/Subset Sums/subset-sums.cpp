//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void recursion(vector<int> &a,int i,vector<int> ds,vector<int> &ans,int sum)
{
    //base condition...
    if(a.size()==i)
    {
        ans.push_back(sum);
        return;
    }
    // pick condition..
    sum+=a[i];
    ds.push_back(a[i]);
    recursion(a,i+1,ds,ans,sum);
    // do not pick condition..
    sum-=a[i];
    ds.pop_back();
    recursion(a,i+1,ds,ans,sum);
}
    vector<int> subsetSums(vector<int> a, int n) {
       vector<int> ans;
       recursion(a,0,{},ans,0);
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends