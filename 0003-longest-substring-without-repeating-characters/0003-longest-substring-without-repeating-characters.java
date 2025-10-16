class Solution {
  public static int lengthOfLongestSubstring(String s) {
        int ans = 0;
        HashMap<Character, Integer> mp = new HashMap<>();
        int i = 0;
        int j = 0;
        while (j < s.length() && i <= j) {
            char c = s.charAt(j);
            while (mp.get(c) != null) {
                char d = s.charAt(i);
                mp.put(d, mp.get(d) - 1);
                if (mp.get(d) == 0) {
                    mp.remove(d);
                }
                i++;
            }
            mp.put(c, mp.getOrDefault(c, 0) + 1);
            ans = Math.max(ans, mp.size());
            j++;
        }
        return ans;
    }
}