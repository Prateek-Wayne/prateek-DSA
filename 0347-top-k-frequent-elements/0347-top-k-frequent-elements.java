
class Pairs {
    Integer first;
    Integer second;

    Pairs(Integer x, Integer y) {
        this.first = x;
        this.second = y;
    }

    public Integer getFirst() {
        return first;
    }

    public Integer getSecond() {
        return second;
    }

}

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
         HashMap<Integer, Integer> mp = new HashMap<>();
        for (int num : nums) {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }

        PriorityQueue<Pairs> minHeap = new PriorityQueue<>((a, b) -> {
            if (b.getSecond() == a.getSecond()) {
                return a.getFirst() - b.getFirst();
            }
            return a.getSecond() - b.getSecond();
        });
        // for (Map.Entry<KeyType, ValueType> entry : map.entrySet()) to get both key
        // and value.
        // for (KeyType key : map.keySet()) to get keys.
        // for (ValueType value : map.values()) to get values.
        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            Pairs temp = new Pairs(entry.getKey(), entry.getValue());
            minHeap.add(temp);
            if (minHeap.size() > k) {
                minHeap.poll();
            }
        }
        int[] ans = new int[k];
        int i = 0;
        while (minHeap.size() > 0) {
            ans[i] = minHeap.poll().first;
            i++;
        }
        return ans;
    }
}