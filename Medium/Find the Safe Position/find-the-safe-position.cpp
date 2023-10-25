//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int safePos(int n, int k) {
        // code here
       vector<int> v;
       for(int i=1;i<=n;i++)
       {
           v.push_back(i);
       }
       int p=0;
       while(v.size()>1)
       {    
           p=(p+(k-1))%v.size();
           v.erase(v.begin()+p);
       }
       return v[0];
       
          
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends