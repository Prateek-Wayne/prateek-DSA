#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<ll> st;
    vector<ll> ans;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && st.top()<=arr[i])
            st.pop();
        if(st.empty())
        {
            ans.push_back(-1);
        }
        else{
            ans.push_back(st.top());
        }
        st.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    // vector<long long> arr = {1, 3, 2, 4};
    nextLargerElement(arr, arr.size());
}