class Solution {
 public int numberOfSubstrings(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();
        int i = 0;
        int j = 0;
        int n = s.length();
        int count = 0;
        while (j < n) {
            char c = s.charAt(j);
            mp.put(c, mp.getOrDefault(c, 0) + 1);
            while (mp.size() == 3) {
                count += n - j;
                char ci = s.charAt(i);
                mp.put(ci, mp.get(ci) - 1);
                if (mp.get(ci) == 0)
                    mp.remove(ci);
                i++;
            }

            j++;
        }
        return count;
    }
}