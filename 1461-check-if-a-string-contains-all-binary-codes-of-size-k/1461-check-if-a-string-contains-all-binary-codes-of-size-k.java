class Solution {
    public boolean hasAllCodes(String s, int k) {
                HashSet<String> st = new HashSet<>();
        int i = 0;
        int j = 0;
        int n = s.length();
        StringBuffer binaryS = new StringBuffer("");
        while (j < n) {
            binaryS.append(s.charAt(j));
            if (j - i + 1 == k) {
                st.add(binaryS.toString());
                binaryS.deleteCharAt(0);
                i++;
            }
            j++;
        }
        return st.size() == Math.pow(2, k);
    }
}