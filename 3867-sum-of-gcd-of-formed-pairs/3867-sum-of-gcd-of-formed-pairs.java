class Solution {
    int gcd(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    public long gcdSum(int[] nums) {
        int n = nums.length;
        int[] mxSum = new int[n];
        int[] gcd = new int[n];
        mxSum[0] = nums[0];
        gcd[0] = nums[0];
        for (int i = 1; i < n; i++) {
            mxSum[i] = Math.max(mxSum[i - 1], nums[i]);
            gcd[i] = gcd(mxSum[i], nums[i]);
        }

        Arrays.sort(gcd);
        int low = 0, high = n - 1;
        long sum = 0;
        while (low < high) {
            int first = gcd[low];
            int second = gcd[high];
            low++;
            high--;
            sum += gcd(first, second);
        }
        return sum;
    }
}