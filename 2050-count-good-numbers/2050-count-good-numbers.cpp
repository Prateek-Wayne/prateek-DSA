class Solution {
public:
    long long powerHelper(int x, long long n) {
        long long modd = 1e9 + 7;
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        // odd...
        if (n & 1)
            return (x * powerHelper(x, n - 1)) % modd;
        // even...
        else {
            long long half = powerHelper(x, n / 2);
            return (half * half) % modd;
        }
    }

    int countGoodNumbers(long long n) {
        long long oddPlaces = n / 2;
        long long evenPlaces = (n + 1) / 2;
        long long modd = 1e9 + 7;

        long long oddGoodNumber = powerHelper(4, oddPlaces) % modd;
        long long evenGoodNumber = powerHelper(5, evenPlaces) % modd;
        return (evenGoodNumber * oddGoodNumber) % modd;
    }
};