#include<bits/stdc++.h>
using namespace std;

int findSecondLargest(int n, vector<int> &arr)
{
    // Write your code here.
      priority_queue< int,vector<int> ,greater<int>> q;
      set<int> st;
      for(auto i:arr)
        st.insert(i);
        for(auto i:st)
        {
            q.push(i);
            if(q.size()>2)
                q.pop();
        }
        return q.top();
}

int main()
{

    vector<int> arr={-10, -40, -25, -12, -25, -10};
    cout<<findSecondLargest(arr.size(),arr);
}