class Solution {
    public String reverseWords(String s) {
        Stack<String> st = new Stack<>();
        int i = 0;
        int n = s.length();
        String temp = new String();
        while (i < n) {
            if (s.charAt(i) == ' ') {
                if (temp.length() != 0) {
                    st.push(temp);
                    temp = "";
                }
            } else if (s.charAt(i) != ' ') {
                temp += s.charAt(i);
            }
            i++;
        }
        if (temp.length() != 0) {
            st.push(temp);
        }
        String ans = "";
        while (!st.isEmpty()) {
            String tempS = st.pop();
            if (st.size() == 0) {
                ans += tempS;
            } else
                ans += tempS+" ";
        }

        return ans;
    }
}