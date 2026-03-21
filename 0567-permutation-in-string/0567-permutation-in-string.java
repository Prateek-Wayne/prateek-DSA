class Solution {
 public boolean checkInclusion(String s1, String s2) {
        HashMap<Character, Integer> mp1 = new HashMap<>();
        HashMap<Character, Integer> mp2 = new HashMap<>();
        for (int i = 0; i < s1.length(); i++) {
            Character c = s1.charAt(i);
            mp1.put(c, mp1.getOrDefault(c, 0) + 1);
        }
        int n1 = s1.length();
        int n = s2.length();
        int i = 0;
        int j = 0;
        while (j < n) {
            Character cj = s2.charAt(j);
            mp2.put(cj, mp2.getOrDefault(cj, 0) + 1);
            if (j - i + 1 == n1) {
                if (mp1.equals(mp2))
                    return true;
            } else {
                while (j - i + 1 > n1) {
                    Character ci = s2.charAt(i);
                    mp2.put(ci, mp2.get(ci) - 1);
                    if (mp2.get(ci) == 0)
                        mp2.remove(ci);
                    i++;
                }
                if (j - i + 1 == n1) {
                    if (mp1.equals(mp2))
                        return true;
                }
            }
            j++;
        }
        return false;
    }
}