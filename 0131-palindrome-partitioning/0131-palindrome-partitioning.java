class Solution {
    boolean checkPalindrom(String s, int start, int end) {
        while (start <= end) {
            if (s.charAt(start) != s.charAt(end))
                return false;
            start++;
            end--;
        }
        return true;

    }

    void helper(String s, int index, List<String> ds, List<List<String>> ans) {
        int n = s.length();
        if (index == s.length()) {
            ans.add(new ArrayList<>(ds));
            return;
        }
        for (int i = index; i < n; i++) {
            if (checkPalindrom(s, index, i)) {
                ds.add(s.substring(index, i+1));
                helper(s, i+1, ds, ans);
                ds.removeLast();
            }
        }
    }

    public List<List<String>> partition(String s) {
        List<String> ds = new ArrayList<>();
        List<List<String>> ans = new ArrayList<>();
        helper(s, 0, ds, ans);
        return ans;
    }
}