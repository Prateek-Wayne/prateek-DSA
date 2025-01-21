class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
    int n = nums.size();
    // vector<int> arr=nums;
    // for(int i=0;i<n;i++)
    //     arr.push_back(nums[i]);
    
    vector<int> ans(n, -1);
    for (int i = 2*n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i%n])
            st.pop();
        if (st.empty())
            ans[i%n] = -1;
        else
            ans[i%n] = st.top();
        st.push(nums[i%n]);
    }
    // vector<int> ans2(ans.begin(),ans.begin()+n);
    // return ans2;
    return ans;
    }
};