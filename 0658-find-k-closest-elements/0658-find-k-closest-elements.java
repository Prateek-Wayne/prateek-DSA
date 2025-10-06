
class Pairs {
    int first;
    int second;

    Pairs(int x, int y) {
        this.first = x;
        this.second = y;
    }

    public int getFirst() {
        return first;
    }

    public int getSecond() {
        return second;
    }

}

class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        PriorityQueue<Pairs> maxHeap = new PriorityQueue<>(
                (a, b) -> {
                    if (a.getFirst() == b.getFirst()) {
                        return b.getSecond() - a.getSecond(); // larger value = worse (comes first)
                    }
                    return b.getFirst() - a.getFirst(); // larger distance = worse (comes first)
                });

        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            Pairs p = new Pairs(Math.abs(x - arr[i]), arr[i]);
            maxHeap.add(p);
            if (maxHeap.size() > k)
                maxHeap.poll();
        }
        while (maxHeap.size() != 0) {
            Pairs p = maxHeap.poll();
            ans.add(p.second);
        }
          Collections.sort(ans);
        return ans;

    }
}