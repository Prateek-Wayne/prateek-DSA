class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
    int n = nums.size();
    vector<int> arr=nums;
    for(int i=0;i<n;i++)
        arr.push_back(nums[i]);
    
    vector<int> ans(n+n, -1);
    for (int i = 2*n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();
        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();
        st.push(arr[i]);
    }
    vector<int> ans2(ans.begin(),ans.begin()+n);
    return ans2;
    }
};