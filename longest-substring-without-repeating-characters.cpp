#include <bits/stdc++.h>
using namespace std;

void lengthOfLongestSubstring(string s)
{
    unordered_set<char> st;
    int left=0;
    int right=0;
    int ans=0;
    int n=s.length();
    while(right<n)
    {
        auto iter=st.find(s[right]);
        if(iter!=st.end())
        {
            while(iter!=st.end())
            {
                st.erase(s[left]);
                left++;
                iter = st.find(s[right]);
            }
        }
        st.insert(s[right]);
        ans=max(ans,right-left+1);

        right++;
    }
    cout<<ans;
}

int main()
{
    string s = "kubdypzxdivrqa";
    lengthOfLongestSubstring(s);
    // unordered_set<char> st;
    // for(int i=0;i<s.length();i++)
    // {
    //     st.insert(s[i]);
    // }
    // for(auto i:st)
    //     cout<<i<<" ";
    // auto iter=st.find('k');
    // st.erase(iter,st.end());

    // cout<<"\nNEW\n";
    // for(auto i:st)
    //     cout<<i<<" ";

    return 0;
}