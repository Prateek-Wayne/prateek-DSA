//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isPrime(int n) {
        // code here
        int count=0;
        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                count+=2;
                if((n/i)==i)
                    count-=1;
            }
            if(count>2)
                return false;
        }
        if(count==2)
            return true;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << (ob.isPrime(N) ? "true" : "false") << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends