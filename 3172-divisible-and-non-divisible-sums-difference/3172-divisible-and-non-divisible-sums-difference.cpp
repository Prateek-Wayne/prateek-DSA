class Solution {
public:
    int differenceOfSums(int n, int m) {
        long long sumk,sigma;
        int k=floor(float(n/m));
        sigma=n*(n+1)/2;
        sumk=m*(k*(k+1)/2);
        return sigma-2*sumk;
    }
};