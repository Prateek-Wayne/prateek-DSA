class Solution {
public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            Character c = s.charAt(i);
            if (c == '{' || c == '[' || c == '(')
                st.add(c);
            else {
                if (st.isEmpty())
                    return false;
                Character top = st.peek();
                if (top == '(' && c == ')')
                    st.pop();
                else if (top == '{' && c == '}')
                    st.pop();
                else if (top == '[' && c == ']')
                    st.pop();
                else
                    st.add(c);
            }
        }
        return st.isEmpty();

    }
}