class Solution {
 public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();
        int i = 0;
        int j = 0;
        int n = s.length();
        int ans = 0;
        while (j < n) {
            Character charJ = s.charAt(j);
            mp.put(charJ, mp.getOrDefault(charJ, 0) + 1);
            if (j - i + 1 == mp.size()) {
                ans = Math.max(ans, mp.size());
            } else if (j - i + 1 > mp.size()) {
                Character charI = s.charAt(i);
                // remove for i...
                mp.put(charI, mp.get(charI) - 1);
                if (mp.get(charI) == 0)
                    mp.remove(charI);
                i++;
                if (j - i + 1 == mp.size())
                    ans = Math.max(ans, mp.size());
            }
            j++;
        }
        return ans;
    }
}