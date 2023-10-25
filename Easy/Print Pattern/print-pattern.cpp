//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void print(int n,int o,int k,bool &flag,vector<int> & v)
{
    if(n==o && flag==true)
        return;
    else{
        if(n<=0)
        {
            k*=-1;
        }
        v.push_back(n);
        n-=k;
        if(n==o)
            flag=true;
        print(n,o,k,flag,v);
    }
}

vector<int> pattern(int N){
    vector<int> v;
    bool flag=false;
    print(N,N,5,flag,v);
    v.push_back(N);
    return v;
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
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends