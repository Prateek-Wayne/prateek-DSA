#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> threeSum(vector<int> &arr)
void threeSum(vector<int> &arr)
{
    set<vector<int>> st;
    for (int i = 0; i < arr.size(); i++)
    {
        set<int> seen;
        for (int j = i + 1; j < arr.size(); j++)
        {
            int target = -(arr[i] + arr[j]);
            if (seen.find(target) != seen.end())
            {
                vector<int> temp = {arr[i], arr[j], target};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            seen.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;

        cout<<"Printing result"<<endl;
    for(auto i:st)
    {
        for(auto j:i)
            cout<<j<<",";
        cout<<endl;
    }
}

int main()
{
    // vector<int> arr={-1,0,1,2,-1,-4};
    vector<int> arr = {0, 0, 0};
    threeSum(arr);
}