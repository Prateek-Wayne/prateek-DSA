class Solution {
   static void helper(StringBuffer ds, int n, int close, int open, List<String> ans) {
        if (ds.length() == 2 * n) {
            ans.add(ds.toString());
            return;
        }
        if (open < n) {
            ds.append('(');
            open = open + 1;
            helper(ds, n, close, open, ans);
            open = open - 1;
            ds.deleteCharAt(ds.length() - 1);
        }
        if (close < open) {
            ds.append(')');
            close = close + 1;
            helper(ds, n, close++, open, ans);
            close = close - 1;
            ds.deleteCharAt(ds.length() - 1);
        }
    }

    public static List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        StringBuffer ds = new StringBuffer();
        ds.append('(');
        helper(ds, n, 0, 1, ans);
        return ans;

    }
}