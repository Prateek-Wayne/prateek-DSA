class Solution {
    void helper(int n, StringBuilder ds, List<String> ans) {
        if (ds.length() == n) {
            ans.add(new StringBuilder(ds).toString());
            return;
        }
        char[] iterate = new char[] { 'a', 'b', 'c' };
        for (char c : iterate) {
            int length = ds.length();
            if (length == 0 || ds.charAt(length - 1) != c) {
                ds.append(c);
                helper(n, ds, ans);
                ds.deleteCharAt(ds.length() - 1);
            }
        }
    }

    public String getHappyString(int n, int k) {
        StringBuilder ds = new StringBuilder("");
        List<String> ans = new ArrayList<>();
        helper(n, ds, ans);
        if (ans.size() < k)
            return "";
        return ans.get(k-1);

    }
}