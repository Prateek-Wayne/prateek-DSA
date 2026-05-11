class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 1;
        int n = digits.length;
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] + carry > 9) {
                digits[i] = 0;
                carry = 1;
            } else {
                digits[i] = digits[i] + carry;
                carry = 0;
                return digits;
            }
        }
        int[] ans = new int[n + 1];
        ans[0] = carry;
        for (int i = 0; i < n; i++) {
            ans[i + 1] = digits[i];
        }
        return ans;
    }
}