#include <bits/stdc++.h>
using namespace std;


vector<int> nse(vector<int> arr)
{
    stack<int> st;//stores indexes ... 🔮
    vector<int> ans;
    int n=arr.size();
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
        {
            st.pop();
        }
        if(st.empty())
            ans.push_back(n);
        else
            ans.push_back(st.top());
        st.push(i);
    }
    return ans;
}
vector<int> pse(vector<int> arr)
{
    stack<int> st;//stores indexes ... 🔮
    vector<int> ans;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
        {
            st.pop();
        }
        if(st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top());
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    vector<int> nseArray=nse(heights);
    vector<int> pseArray=pse(heights);
    int n=heights.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int width=nseArray[i]-pseArray[i]-1;
        ans=max(width*heights[i],ans);
    }
    return ans;
}

int main()
{
    vector<int> heights={1,1};
    largestRectangleArea(heights);
}