const int MAX_N = sqrt(100000);
vector<bool> is_prime(MAX_N + 1, true);
vector<int> primes;

class Solution {
public:
    const int MODULO = 1e9 + 7; 
    void Sieve() {
        if (!primes.empty()) return;
        is_prime[0] = is_prime[1] = false;
        const int n_sqrt = sqrt(MAX_N);
        for (int i = 2; i <= n_sqrt; i++) {
            if (is_prime[i]) {
                primes.push_back(i);
                for (int j = i * i; j <= MAX_N; j += i)
                    is_prime[j] = false;
            }
        }
        for (int i = n_sqrt + 1; i <= MAX_N; i++) {
            if (is_prime[i]) primes.push_back(i);
        }
    } 
    int primeScore(int num) {
        if (num <= MAX_N && is_prime[num]) return 1;
        int num_sqrt = sqrt(num);
        int prime_count = 0;
        for (int p : primes) {
            if (p > num_sqrt) break;
            if (num % p != 0) continue;
            while (num % p == 0) num /= p;
            prime_count++;
        }
        prime_count += (num > 1);
        return prime_count;
    } 
    long long modExponentiation(long long base, int exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % MODULO;
            base = (base * base) % MODULO;
            exp >>= 1;
        }
        return result;
    } 
    int maximumScore(vector<int>& numbers, int k) {
        const int length = numbers.size();
        Sieve(); 
        vector<int> prime_scores(length), left_limit(length), right_limit(length);
        for (int i = 0; i < length; i++) {
            prime_scores[i] = primeScore(numbers[i]);
        } 
        stack<int> st;
        for (int i = 0; i < length; i++) {
            while (!st.empty() && prime_scores[i] > prime_scores[st.top()]) st.pop();
            left_limit[i] = st.empty() ? -1 : st.top();
            st.push(i);
        } 
        while (!st.empty()) st.pop();
        for (int i = length - 1; i >= 0; i--) {
            while (!st.empty() && prime_scores[i] >= prime_scores[st.top()]) st.pop();
            right_limit[i] = st.empty() ? length : st.top();
            st.push(i);
        } 
        vector<pair<int, int>> number_indices(length);
        for (int i = 0; i < length; i++) {
            number_indices[i] = {numbers[i], i};
        } 
        stable_sort(number_indices.rbegin(), number_indices.rend()); 
        long long result = 1;
        for (int i = 0; i < length && k > 0; i++) {
            auto [value, index] = number_indices[i];
            int exp = min((long long)(index - left_limit[index]) * (right_limit[index] - index), (long long)k);
            result = (result * modExponentiation(value, exp) % MODULO);
            k -= exp;
        } 
        return result;
    }
};
