class Solution {
public:
    long long coloredCells(int N) {
        long long n=N;
        long long ans=(n*n)+((n-1)*(n-1));
        // return ans%10000000000;
        return ans;
    }
};