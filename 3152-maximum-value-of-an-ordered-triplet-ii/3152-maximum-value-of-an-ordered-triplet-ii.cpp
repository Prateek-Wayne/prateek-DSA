class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> NGR(n, -1);
        vector<int> NGL(n, -1);
        for (int i = n - 2; i >= 0; i--) {
            NGR[i] = max(nums[i + 1], NGR[i + 1]);
        }
        NGL[0] = nums[0];
        for (int i = 1; i < n; i++) {
            NGL[i] = max(nums[i - 1], NGL[i - 1]);
        }
        long long ans = 0;
        for (int x = 1; x < n - 1; x++) {
            int i = NGL[x];
            int j = nums[x];
            int k = NGR[x];

            if (i > j) {
                long long solution = (long long)(i - j) * k;
                ans = max(ans, solution);
            }
        }

        return ans;
    }
};