class Solution {
  public boolean isPrime(int n) {
        int limit = (int) Math.sqrt(n);
        if (n < 2)
            return false;
        for (int i = 2; i <= limit; i++) {
            if (i != n && n % i == 0)
                return false;
        }
        return true;
    }

    public int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            int bit = i;
            int count = 0;
            while (bit != 0) {
                count += (bit & 1) == 1 ? 1 : 0;
                bit = bit >> 1;
            }
            if (isPrime(count))
                ans++;

        }
        return ans;

    }
}