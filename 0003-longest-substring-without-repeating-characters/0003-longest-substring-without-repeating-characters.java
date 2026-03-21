class Solution {
 public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();
        int i = 0;
        int j = 0;
        int n = s.length();
        int ans = 0;
        while (j < n) {
            Character c = s.charAt(j);
            mp.put(c, mp.getOrDefault(c, 0) + 1);
            if (j - i + 1 == mp.size()) {
                ans = Math.max(ans, j - i + 1);
            } else {
                // remove calculations..
                while (j - i + 1 > mp.size()) {
                    Character ith = s.charAt(i);
                    mp.put(ith, mp.get(ith) - 1);
                    if (mp.get(ith) == 0) {
                        mp.remove(ith);
                    }
                    i++;
                }
                if (j - i + 1 == mp.size()) {
                    ans = Math.max(ans, j - i + 1);
                }

            }
            j++;
        }
        return ans;
    }
}