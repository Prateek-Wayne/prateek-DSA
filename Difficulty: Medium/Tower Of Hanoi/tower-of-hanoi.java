class Solution {
    static void helper(int n, int s, int h, int d, int[] count) {
        // base condition
        if (n == 1) {
            count[0]++;
            return;
        }
        helper(n - 1, s, d, h, count);
        count[0]++;
        helper(n - 1, h, s, d, count);

    }

    public static int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        int[] count = new int[] { 0 };
        helper(n, from, aux, to, count);
        return count[0];
    }
}
