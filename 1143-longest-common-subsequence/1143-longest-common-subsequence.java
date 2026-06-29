class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int index1 = text1.length();
        int index2 = text2.length();
        int[] curr = new int[index2 + 1];
        int[] prev = new int[index2 + 1];

        for (int i = 1; i <= index1; i++) {
            for (int j = 1; j <= index2; j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = Math.max(curr[j - 1], prev[j]);
                }
            }
            int[] temp = prev;
            prev = curr;
            curr = temp;  
        }
        return prev[index2];
    }
}