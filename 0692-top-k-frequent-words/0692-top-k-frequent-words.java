class Pair {
    String first;
    int second;

    Pair(String first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        PriorityQueue<Pair> minHeap = new PriorityQueue<>((a, b) -> {
            if (a.second == b.second) {
                // Reverse: keep lexicographically smaller words
                return b.first.compareTo(a.first);
            }
            return a.second - b.second;
        });
        HashMap<String, Integer> mp = new HashMap<>();
        for (String i : words) {
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }
        mp.forEach((key, value) -> {
            minHeap.add(new Pair(key, value));
            if (minHeap.size() > k)
                minHeap.poll();
        });
        List<String> ans = new ArrayList<>();
        while (!minHeap.isEmpty()) {
            ans.add(minHeap.poll().first);
        }
        return ans.reversed();
    }
}