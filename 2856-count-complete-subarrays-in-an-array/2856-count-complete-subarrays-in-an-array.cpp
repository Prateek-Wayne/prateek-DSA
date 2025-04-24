class Solution {
public:
int countCompleteSubarrays(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> mp;
    set<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        st.insert(nums[i]);
    }
    int uniqueCounts = st.size();
    int low = 0, high = 0, ans = 0;
    while (high < n)
    {
        mp[nums[high]]++;
        if (mp.size() == uniqueCounts)
        {
            ans += n - high;
            while (mp.size() == uniqueCounts)
            {
                mp[nums[low]]--;
                if (mp[nums[low]] == 0)
                {
                    mp.erase(nums[low]);
                }
                if (mp.size() == uniqueCounts)
                {
                    ans += n - high;
                }
                low++;
            }
        }
        high++;
    }
    return ans;
}
};