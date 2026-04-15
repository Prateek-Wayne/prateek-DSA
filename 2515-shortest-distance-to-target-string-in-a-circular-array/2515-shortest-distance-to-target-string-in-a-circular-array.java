class Solution {
    public int closestTarget(String[] words, String target, int startIndex) {
        int n = words.length;
        for (int i = 0; i < n; i++) {
            int first = (startIndex - i + n) % n;
            int second = (i + startIndex) % n;
            if (words[first].equals(target) || words[second].equals(target))
                return i;
        }
        return -1;
    }
}