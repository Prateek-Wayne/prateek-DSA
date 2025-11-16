class Solution {
    public boolean isAnagram(String s, String t) {
                if (s.length() != t.length())
            return false;
        int[] p = new int[26];
        int[] q=new int[26];
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int c1 = s.charAt(i) - 'a';
            int c2 = t.charAt(i) - 'a';
            p[c1] = p[c1] + 1;
            q[c2] = q[c2] + 1;
        }
       for (int i = 0; i < p.length; i++) {
            if (p[i]!=q[i])
                return false;
        }
        return true;
    }
}