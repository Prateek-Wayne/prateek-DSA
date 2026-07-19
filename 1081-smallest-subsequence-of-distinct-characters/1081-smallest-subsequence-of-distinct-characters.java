class Solution {
  public static String smallestSubsequence(String s) {
        Stack<Character> st = new Stack<>();
        Set<Character> exist = new HashSet<>();
        int[] lastVisited = new int[26];
        for (int i = 0; i < s.length(); i++) {
            int index = s.charAt(i) - 'a';
            lastVisited[index] = i;
        }
        for (int i = 0; i < s.length(); i++) {
            Character c = s.charAt(i);
            if(exist.contains(c))
                continue;
            while (!st.isEmpty() && st.peek() > c && lastVisited[st.peek() - 'a'] > i) {
                exist.remove(st.peek());
                st.pop();
            }
            st.add(c);
            exist.add(c);
        }

        StringBuilder ans = new StringBuilder();
        while (!st.isEmpty()) {
            ans.append(st.pop());
        }
        return ans.reverse().toString();
    }
}