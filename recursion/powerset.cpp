#include<bits/stdc++.h>
using namespace std;

void helper(string s,string ds,vector<string> & ans,int ind)
{
    //  base condition...
    if(ind==(s.size()))
        {   sort(ds.begin(),ds.end());
            if(ds.size()!=0)
                ans.push_back(ds);
            return ;
        }
    // tick condition...
    ds.push_back(s[ind]);
    helper(s,ds,ans,ind+1);

    // drop condition...
    ds.pop_back();
    helper(s,ds,ans,ind+1);

    
}

vector<string> AllPossibleStrings(string s){
    vector<string> ans;
    helper(s, "", ans, 0);
    for (const auto& str : ans) {
        cout << str << endl;
    }
    
    return ans;
}
int main()
{
    vector<string> ans=AllPossibleStrings("abc");
    cout<<endl<<ans.size();
 return 0;
}