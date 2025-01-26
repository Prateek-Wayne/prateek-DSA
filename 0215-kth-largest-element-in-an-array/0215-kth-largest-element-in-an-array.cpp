class Solution {
public:
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> maxHeap;
    for (int i = 0; i < nums.size(); i++)
    {
        maxHeap.push(nums[i]);
        if (maxHeap.size() > k)
            maxHeap.pop();
    }
    return maxHeap.top();
}};