#include<bits/stdc++.h>
using namespace std;

void helper(string ds,vector<string> & ans,int n,int ind)
{
    // base..
    if(ind==n)
    {
        ans.push_back(ds);
        return;
    }
    // check if previous is '0'..
    if(ds[ind-1]=='0')
        {
            ds.push_back('1');
            helper(ds,ans,n,ind+1);
        }
    else{
        ds.push_back('0');
        helper(ds,ans,n,ind+1);
        // remove condition...
        ds.pop_back();
        ds.push_back('1');
        helper(ds,ans,n,ind+1);

    }

}

vector<string> validStrings(int n) {
        vector<string> ans;
        string ds0 = "0";
        string ds1 = "1";
        helper(ds0, ans, n, 1);
        helper(ds1, ans, n, 1);
        for(const auto &str : ans) {
            cout << str << endl;
        }
        return ans;
        
    }

int main()
{
    vector<string> ans=validStrings(1);
 return 0;
}