class Solution {
    public boolean hasSameDigits(String s) {
        int n = s.length() - 1;
        int left = 0;
        int right = 0;

        for (int i = 0; i <= n; i++) {
            int val = s.charAt(i) - 48;
            if (i <= n - 1)
                left = (left + getMod10(n - 1, i) * val) % 10;
            if (i >= 1)
                right = (right + getMod10(n - 1, i - 1) * val) % 10;
        }

        return left == right;
    }
    
    private int getMod10(int n, int i) {
        int[][] fast5 = {
            {1,0,0,0,0},
            {1,1,0,0,0},
            {1,2,1,0,0},
            {1,3,3,1,0},
            {1,4,1,4,1}
        };
        int[][] xunzhi = {
            {0,6,2,8,4},
            {5,1,7,3,9}
        };

        int mod2 = 1;
        int mod5 = 1;

        int a = n, b = i;
        while (a > 0 || b > 0) {
            int na = a & 1;
            int nb = b & 1;
            if (nb == 1 && na == 0) {
                mod2 = 0;
                break;
            }
            a >>= 1;
            b >>= 1;
        }

        a = n;
        b = i;
        while (a > 0 || b > 0) {
            int na = a % 5;
            int nb = b % 5;
            mod5 = (mod5 * fast5[na][nb]) % 5;
            a /= 5;
            b /= 5;
        }

        return xunzhi[mod2][mod5];
    }
}
