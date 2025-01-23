//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int binaryToDecimal(string &s) {
        // Code here.
        int pow=1;
        int ans=0;
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='1')
                ans+=pow;
            pow=pow*2;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.binaryToDecimal(str);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends