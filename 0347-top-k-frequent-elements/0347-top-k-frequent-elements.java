class Pair {
    int first;
    int second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        PriorityQueue<Pair> minHeap = new PriorityQueue<>((a, b) -> a.second - b.second);
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i : nums) {
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }
        mp.forEach((key, value) -> {
            minHeap.add(new Pair(key, value));
            if (minHeap.size() > k)
                minHeap.poll();
        });
        int[] arr = new int[minHeap.size()];
        int counter = 0;
        while (!minHeap.isEmpty()) {
            arr[counter] = minHeap.poll().first;
            counter++;

        }
        return arr;
    }
}