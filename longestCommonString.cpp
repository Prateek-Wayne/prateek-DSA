#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{   
    if(nums.size()==0)
        return 0;
    set<int> st;
    for(auto i:nums)
        st.insert(i);

    int longest=1;

    // iterate through set

    for(auto i:st)
    {   
        if(st.find(i-1)==st.end())
        {   
            int x=i;
            int count=1;
            while(st.find(x+1)!=st.end())
            {
                count++;
                x++;
            }
            longest=max(longest,count);
        }
    }

    return longest;
}

int main()
{
    vector<int> arr={102,4,100,101,3,2,1,1};
    cout<<longestConsecutive(arr);
}