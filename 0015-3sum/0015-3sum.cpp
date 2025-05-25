class Solution {
public:

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    set<vector<int>> st;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0)
            {
                vector<int> triplets = {nums[i], nums[j], nums[k]};
                sort(triplets.begin(), triplets.end());
                st.insert(triplets);
                j++;k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
                k--;
        }
    }
    for (auto i : st)
    {
        ans.push_back(i);
    }
    return ans;
}
};