class Solution {
    public int longestKSubstr(String s, int k) {
        // code here
        HashMap<Character, Integer> mp = new HashMap<>();
        int i = 0;
        int j = 0;
        int n = s.length();
        int ans = -1;
        while (j < n) {
            char charJ = s.charAt(j);
            mp.put(charJ, mp.getOrDefault(charJ, 0) + 1);
            if (mp.size() == k) {
                ans = Math.max(ans, j - i + 1);
            } else if (mp.size() > k) {
                while (mp.size() > k) {
                    char charI = s.charAt(i);
                    mp.put(charI, mp.get(charI) - 1);
                    if (mp.get(charI) == 0) {
                        mp.remove(charI);
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
        
    }
}