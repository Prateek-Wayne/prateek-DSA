#include <bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(int price[], int n)
{
    stack<int> st;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && price[st.top()]<=price[i])
            st.pop();
        if(st.empty())
            ans.push_back(i+1);
        else{
            ans.push_back(i-st.top());
        }
        st.push(i);

    }
    return ans;

}

int main()
{
}