class Solution {
public:

bool calculateResult(vector<int> &nums, int devisor, int threshold)
{
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        result += ceil(double(nums[i]) / double(devisor));
    }
    return result <= threshold;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    if (nums.size() > threshold)
        return -1;
    int high = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
        high = max(high, nums[i]);
    int low = 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (calculateResult(nums, mid, threshold))
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return low;
}
};