class Solution {
  public boolean checkInclusion(String p, String s) {
        List<Integer> ans = new ArrayList<>();
        HashMap<Character, Integer> mp = new HashMap<>();
        for (int i = 0; i < p.length(); i++) {
            mp.put(p.charAt(i), mp.getOrDefault(p.charAt(i), 0) + 1);
        }
        int i = 0;
        int j = 0;
        int n = s.length();
        int k = p.length();
        HashMap<Character, Integer> slidingMap = new HashMap<>();
        while (j < n) {
            Character charJ = s.charAt(j);
            slidingMap.put(charJ, slidingMap.getOrDefault(charJ, 0) + 1);
            if (j - i + 1 == k) {
                Character charI = s.charAt(i);
                if (mp.equals(slidingMap)) {
                    return true;
                }
                slidingMap.put(charI, slidingMap.get(charI) - 1);
                if (slidingMap.get(charI) == 0) {
                    slidingMap.remove(charI);
                }
                i++;
            }
            j++;
        }
        return false;
    }
}