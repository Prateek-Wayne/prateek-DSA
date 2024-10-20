//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
void helper(string &s,int index,vector<string> &ans){
    //
    if(index==s.size())
    {
        ans.push_back(s);
        return;
    }
    //if previose is 1..
    if(s[index-1]=='1')
    {
        s[index]='0';
        helper(s,index+1,ans);
    }
    else if(s[index-1]=='0')
    {
        s[index]='0';
        helper(s,index+1,ans);
        s[index]='1';
        helper(s,index+1,ans);
    }
}

vector<string> generateBinaryStrings(int num)
{
    string s;
    vector<string> ans;
    for(int i=0;i<num;i++)
        s.push_back('0');
    helper(s,1,ans);
    s="";
    for(int i=0;i<num;i++)
    {
        s.push_back('1');
    }
    helper(s,1,ans);
    return ans;
}
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends