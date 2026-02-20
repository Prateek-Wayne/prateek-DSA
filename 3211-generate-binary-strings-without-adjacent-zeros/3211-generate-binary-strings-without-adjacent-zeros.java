class Solution {
 static void helper(List<String> ans, StringBuffer ds, int n) {
        if (ds.length() == n) {
            ans.add(ds.toString());
            return;
        }
        if (ds.charAt(ds.length() - 1) == '1') {
            ds.append('0');
            helper(ans, ds, n);
            ds.deleteCharAt(ds.length() - 1);
            ds.append('1');
            helper(ans, ds, n);
            ds.deleteCharAt(ds.length() - 1);
        } else {
            ds.append('1');
            helper(ans, ds, n);
            ds.deleteCharAt(ds.length() - 1);
        }
    }

    public static List<String> validStrings(int n) {
        List<String> ans = new ArrayList<>();
        helper(ans, new StringBuffer("0"), n);
        helper(ans, new StringBuffer("1"), n);

        return ans;
    }
}