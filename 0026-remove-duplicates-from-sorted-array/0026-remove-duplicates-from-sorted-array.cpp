class Solution {
public:
int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int i = 1;
    for (int j = 1; j < n; j++)
    {
        if (nums[i - 1] != nums[j])
        {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
};