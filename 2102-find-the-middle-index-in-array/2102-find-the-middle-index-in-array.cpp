class Solution {
public:
int findMiddleIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = nums[0];
    
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    for (int i = 0; i < n; i++) {
        int left = (i == 0) ? 0 : prefixSum[i - 1];
        int right = prefixSum[n - 1] - prefixSum[i];
        if (left == right) {
            return i;
        }
    }
    return -1;
}

};