#include <bits/stdc++.h>
using namespace std;

// void nextGreaterElement(vector<int> &nums2)
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<int> st;
    vector<int> ngl(1000,-1);
    vector<int> ans(nums1.size(),-1);
    for(int i=nums2.size()-1;i>=0;i--)
    {
        while(!st.empty()&&st.top()<=nums2[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            ngl[nums2[i]]=-1;
        }
        else
            ngl[nums2[i]]=st.top();

        // always..
        st.push(nums2[i]);
    }
    for(int i=0;i<nums1.size();i++)
    {
        ans[i]=ngl[nums1[i]];
    }
    return ans;
}

int main()
{
    vector<int> nums={1,3,4,2};
    nextGreaterElement(nums);
}