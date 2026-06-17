class Solution {
    public String longestCommonPrefix(String[] strs) {
        String ans="";
        Arrays.sort(strs);
        int n=strs.length;
        for(int i=0;i<strs[0].length();i++){
            if(strs[0].charAt(i)==strs[n-1].charAt(i)){
                ans+=strs[0].charAt(i);
            }
            else
                break;
        }
        return ans;
    }
}