class Solution {
public:

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int k = j + 1, l = n - 1;
            while (k < l)
            {
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                if (sum == target)
                {
                    vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
                    sort(quad.begin(), quad.end());
                    st.insert(quad);
                    k++;
                    l--;
                }
                else if (sum > target)
                {
                    l--;
                }
                else if (sum < target)
                    k++;
            }
        }
    }
    vector<vector<int>> ans;
    for (auto i : st)
    {
        ans.push_back(i);
    }
    return ans;
}
};