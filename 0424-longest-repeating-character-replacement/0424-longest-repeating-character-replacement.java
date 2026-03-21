class Solution {
  public int characterReplacement(String s, int k) {
        HashMap<Character, Integer> mp = new HashMap<>();
        int n = s.length();
        int i = 0;
        int j = 0;
        int ans = 0;
        while (j < n) {
            Character c = s.charAt(j);
            mp.put(c, mp.getOrDefault(c, 0) + 1);
            int maxF = 0;
            for (Character x : mp.keySet()) {
                maxF = Math.max(maxF, mp.get(x));
            }
            boolean canReplace = j - i + 1 - maxF <= k;
            if (canReplace) {
                ans = Math.max(ans, j - i + 1);
            } else {
                while (j - i + 1 - maxF > k) {
                    Character ci = s.charAt(i);
                    mp.put(ci, mp.get(ci) - 1);
                    if (mp.get(ci) == 0)
                        mp.remove(ci);
                    for (Character x : mp.keySet()) {
                        maxF = Math.max(maxF, mp.get(x));
                    }
                    i++;
                }
                for (Character x : mp.keySet()) {
                    maxF = Math.max(maxF, mp.get(x));
                }
                if (j - i + 1 - maxF <= k) {
                    ans = Math.max(ans, maxF);
                }
            }
            j++;
        }
        return ans;
    }
}