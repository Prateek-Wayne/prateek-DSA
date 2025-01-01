//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
private:
 

public:

const int MOD = 1e9 + 7;

void helper(long long index, int n, long long first, long long &ans)
{
    if (index == n)
        return;
    long long temp = 1;
    long long i = first;
    for (; i < first + index; i++)
    {
        // temp = temp * i;
        temp = (temp * i) % MOD;
    }

    ans += temp;
    first = i;
    helper(index + 1, n, i, ans);
}

long long sequence(int n)
{
    long long ans = 0;
    helper(1, n + 1, 1, ans);
    return ans % MOD;
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends