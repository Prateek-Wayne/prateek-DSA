#include <bits/stdc++.h>
using namespace std;

vector<int> NSE(vector<int> arr)
{
    stack<int> st;
    vector<int> ans;
    int n=arr.size();
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
            st.pop();
        if(st.empty())
            ans.push_back(i);
        else
            ans.push_back(st.top());
        st.push(i);
    }
    return ans;
}

vector<int> PSEE(vector<int> arr)
{
    stack<int> st;
    vector<int> ans;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();
        if(st.empty())
            ans.push_back(i);
        else
            ans.push_back(st.top());
        st.push(i);
    }
    return ans;
}

int sumSubarrayMins(vector<int> &arr)
{
    vector<int> nse=NSE(arr);
    vector<int> pse=PSEE(arr);
    int sum=0;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        int left=i-pse[i];
        int right=nse[i]-i;
        sum+=(arr[i])*(right*left);
    }
    return sum;

}
int main()
{
}