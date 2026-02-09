class Solution {
 private static int getInt(Character c) {
        return c - '0';
    }

    public String removeKdigits(String num, int k) {
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < num.length(); i++) {
            while (!st.isEmpty() && getInt(st.peek()) > getInt(num.charAt(i)) && k > 0) {
                st.pop();
                k--;
            }
            st.push(num.charAt(i));
        }
        StringBuilder s = new StringBuilder("");
        while (!st.isEmpty() && k > 0) {
            st.pop();
            k--;
        }
        if (st.isEmpty() && k > 0)
            return "0";
        while (!st.isEmpty()) {
            s.append(st.pop());
        }

        while (s.length() > 0 && s.charAt(s.length() - 1) == '0') {
            s.deleteCharAt(s.length() - 1);
        }
        s.reverse();
        if (s.length() == 0) {
            return "0";
        }
        return s.toString();
    }
}