class Solution {
 static StringBuilder flipBits(StringBuilder s) {
        StringBuilder newS = new StringBuilder("");
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1')
                newS.append(0);
            else
                newS.append('1');
        }
        return newS;
    }

    static void helper(int n, int count, StringBuilder s) {
        if (count == n)
            return;
        StringBuilder newS = new StringBuilder(s);
        s.append('1');
        s.append(flipBits(newS).reverse());
        count++;
        helper(n, count, s);
    }

    public static char findKthBit(int n, int k) {
        StringBuilder s = new StringBuilder("0");
        int count = 0;
        helper(n, count, s);
        return s.charAt(k - 1);
    }
}