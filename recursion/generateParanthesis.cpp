#include <bits/stdc++.h>
using namespace std;

void helper(int open,int close,string ds,vector<string> & ans)
{
    if(open ==0 && close==0)
    {
        ans.push_back(ds);
        return;
    }
    // I will update add ( when there is open !=0
    if(open!=0)
    {   string op1=ds;
        ds.push_back('(');
        helper(open-1,close,ds,ans);
        ds.pop_back();
        // op1.push_back('(');
        // helper(open-1,close,op1);
    }
    if(open<close)
    {
        string op2=ds;
        ds.push_back(')');
        helper(open,close-1,ds,ans);
        ds.pop_back();
        // op2.push_back(')');
        // helper(open,close-1,op2);
    }
}

 vector<string> generateParenthesis(int n)
{   
    vector<string> ans;
    string ds="";
    int open=n;
    int close=n;
    helper(open,close,ds,ans);
    return ans;
    
}

int main()
{   
    generateParenthesis(3);
    return 0;
}