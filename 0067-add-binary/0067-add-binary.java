class Solution {
    public static String calculate(String a, String b) {
        int carry = 0;
        StringBuilder newA = new StringBuilder(a).reverse();
        StringBuilder newB = new StringBuilder(b).reverse();
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < newB.length(); i++) {
            int charB = newB.charAt(i) - '0';
            int charA = newA.charAt(i) - '0';
            int sum = charA + charB + carry;
            carry = 0;
            if (sum == 3) {
                sum = 1;
                carry = 1;
            } else if (sum == 2) {
                sum = 0;
                carry = 1;
            }

            ans.append(sum);
        }
        for (int i = newB.length(); i < newA.length(); i++) {
            int charA = newA.charAt(i) - '0';
            int sum = charA + carry;
            carry = 0;
            if (sum == 2) {
                sum = 0;
                carry = 1;
            }
            ans.append(sum);
        }
        if (carry == 1)
            ans.append(carry);
        return ans.reverse().toString();
    }

    public static String addBinary(String a, String b) {
        int l1 = a.length();
        int l2 = b.length();
        if (l2 <= l1) {
            return calculate(a, b);
        } else
            return calculate(b, a);
    }
}