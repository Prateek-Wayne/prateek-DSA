class Solution {
    final int modd = (int) 1e9 + 7;

    public int concatenatedBinary(int n) {
        int length = 0;
        long ans = 0;
        for (int i = 1; i <= n; i++) {
            // check if power of 2?...
            if ((i & (i - 1)) == 0) {
                length++;
            }
            ans = (((ans << length) % modd) + i) % modd;
        }
        return (int) ans;
    }
}