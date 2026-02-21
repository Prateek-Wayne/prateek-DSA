class Solution {
List<String> ans = new ArrayList<>();

    void helper(StringBuilder s, int n) {
        if (s.length() == n) {
            ans.add(s.toString());
            return;
        }
        //
        int size = s.length();
        if (s.charAt(size - 1) == '0') {
            s.append('1');
            helper(s, n);
            s.deleteCharAt(s.length() - 1);
        }
        if (s.charAt(size - 1) == '1') {
            s.append('0');
            helper(s, n);
            s.deleteCharAt(s.length() - 1);
            s.append('1');
            helper(s, n);
            s.deleteCharAt(s.length() - 1);
        }
        return;
    }

    public List<String> validStrings(int n) {
        helper(new StringBuilder("0"), n);
        helper(new StringBuilder("1"), n);
        return ans;
    }
}