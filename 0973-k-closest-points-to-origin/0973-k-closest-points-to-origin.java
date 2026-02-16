class Pair {
    int first;
    int second;
    int third;

    Pair(int first, int second, int third) {
        this.first = first;
        this.second = second;
        this.third = third;
    }
}

class Solution {
     public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Pair> maxHeap = new PriorityQueue<>((a, b) -> b.first - a.first);
        for (int i = 0; i < points.length; i++) {
            int distance = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            maxHeap.add(new Pair(distance, points[i][0], points[i][1]));

            if (maxHeap.size() > k)
                maxHeap.poll();
        }

        int[][] arr = new int[maxHeap.size()][2];
        int counter = 0;
        while (!maxHeap.isEmpty()) {
            Pair temp = maxHeap.poll();
            arr[counter][0] = temp.second;
            arr[counter][1] = temp.third;
            counter++;
        }
        return arr;
    }
}