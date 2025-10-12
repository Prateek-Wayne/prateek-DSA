class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        if (s.isEmpty())
            return true;
        st.add(s.charAt(0));
        for (int i = 1; i < s.length(); i++) {
            if(st.isEmpty())
                st.add(s.charAt(i));
            else if (s.charAt(i) == ')' && st.peek() == '(' ||
                    s.charAt(i) == '}' && st.peek() == '{' ||
                    s.charAt(i) == ']' && st.peek() == '[')
                st.pop();
            else
                st.add(s.charAt(i));
        }
        return st.isEmpty();

    }
}