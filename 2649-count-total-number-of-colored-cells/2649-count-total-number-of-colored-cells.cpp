class Solution {
public:
    long long coloredCells(int n) {
        long long x=n;
        long long ans= (2*x*x)-(2*x)+1;
        return ans;
    }
};