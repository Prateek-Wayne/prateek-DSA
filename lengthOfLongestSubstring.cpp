#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    map<char,int> mp;
    int ans=0;
    for(int i=0;i<s.length();i++)
    {
        if(mp.find(s[i])!=mp.end())
        {
            auto iter=mp.find(s[i]);
            ans=max(ans,i-iter->second);
        }
        mp[s[i]]=i;

    }
    return ans;
}

int main()
{
    // string s="abcabcbb";
    string s="au";
    cout<<lengthOfLongestSubstring(s);
}