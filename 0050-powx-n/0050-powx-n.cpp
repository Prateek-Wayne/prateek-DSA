class Solution {
public:
    double func(double x, long long n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n < 0) {
            n = abs(n);
            x = 1 / x;
        }
        if (n % 2 == 0)
            return func(x * x, n / 2);
        else
            return x * func(x, n - 1);
    }

    double myPow(double x, int n) {
        int num = n;
        return func(x, num);
    }
};