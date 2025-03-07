class Solution {
public:
    int isPrime(int n) {
        int count = 0;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                count += 2;
                if (n / i == i)
                    count -= 1;
            }
            if (count > 2)
                return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        // int prev = INT_MAX;
        // int next = INT_MAX;
        vector<int> ans = {-1, -1};
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (i > 1) {
                if (isPrime(i))
                    primes.push_back(i);
            }
        }
        if (primes.size() < 2)
            return ans;
        for (int i = 0; i < primes.size() - 1; i++) {
            if (ans[0] == -1)
                ans[0] = primes[i];
            if (ans[1] == -1)
                ans[1] = primes[i + 1];
            if (ans[0] != -1 && ans[1] != -1) {
                int first = primes[i];
                int second = primes[i + 1];
                if ((second - first) < (ans[1] - ans[0])) {
                    ans[0] = first;
                    ans[1] = second;
                }
            }
        }
        return ans;
    }
};