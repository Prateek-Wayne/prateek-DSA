#include <bits/stdc++.h>
using namespace std;

// void count_NGE(int n, vector<int> &arr)
void count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
{
    stack<int> st;
    vector<int> NGR(n,-1);
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && st.top()<=arr[i])
            st.pop();
        
        if(st.empty())
            NGR[i]=-1;
        else
            NGR[i]=st.top();
        
        // always..
        st.push(arr[i]);
    }
    // for(auto i:NGR)
    //     cout<<i<<" ";
    vector<int> ans;
    for(auto i:indices)
    {   int count=0;
        for(int j=i;j<NGR.size();j++)
        {
            if(NGR[j]!=-1)
                count++;
        }
        ans.push_back(count);
    }
    return ans;
}

int main()
{
    vector<int> arr={3, 4, 2, 7, 5, 8, 10, 6};
    vector<int> indices={0, 5};
    count_NGE(arr.size(),arr,indices.size(),indices);
}