class Solution {
public:
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    map<long long, int> mp;
    // if (goal != 0)
    mp[0] = 1;
    int ans = 0;
    long long sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        long long diff = sum - goal;
        if (mp.count(diff))
        {
            ans += mp[diff];
        }
        mp[sum]++;
    }
    return ans;
}
};