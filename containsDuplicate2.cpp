#include <bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int> &arr, int k)
{
    set<int> st;
    int r = 0;
    int l = 0;
    while (r < arr.size())
    {
        if ((r - l) < (k + 1))
        {
            if (st.find(arr[r]) != st.end())
            {
                return true;
            }
            st.insert(arr[r]);
            r++;
        }
        else if ((r - l) == (k + 1))
        {
            st.erase(arr[l]);
            l++;
            if (st.find(arr[r]) != st.end())
            {
                return true;
            }
            st.insert(arr[r]);
            r++;
        }
    }

    return false;
}

int main()
{
    vector<int> ans={1,2,3,1,2,3};
    // vector<int> ans = {1, 2, 3, 1};
    cout << containsNearbyDuplicate(ans, 2);
}