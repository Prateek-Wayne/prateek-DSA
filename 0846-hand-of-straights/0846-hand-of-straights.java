class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if (hand.length % groupSize != 0)
            return false;
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        for (int i : hand) {
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }
        while (mp.size() != 0) {
            Integer first = mp.firstEntry().getKey();
            for (int i = 0; i < groupSize; i++) {
                int next = first + i;
                if (!mp.containsKey(next))
                    return false;
                mp.put(next, mp.get(next) - 1);
                if (mp.get(next) == 0)
                    mp.remove(next);

            }
        }
        return true;
    }
}