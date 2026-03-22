class Solution {
 public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();
        for (String s : tokens) {
            if (s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")) {
                int second = st.pop();
                int first = st.pop();
                if (s.equals("+")) {
                    st.add(first + second);
                } else if (s.equals("-"))
                    st.add(first - second);
                else if (s.equals("*"))
                    st.add(first * second);
                else if (s.equals("/"))
                    st.add(first / second);
            } else {
                Integer number = Integer.parseInt(s);
                st.add(number);
            }
        }
        return st.peek();
    }
}