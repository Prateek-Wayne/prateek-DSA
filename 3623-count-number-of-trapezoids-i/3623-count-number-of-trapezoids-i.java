class Solution {
 public int countTrapezoids(int[][] points) {
        int Modd = (int) 1e9 + 7;
        Map<Integer, Long> mp = new HashMap<>();
        for (int[] arr : points) {
            mp.put(arr[1], mp.getOrDefault(arr[1], (long) 0) + 1);
        }
        List<Long> arr = new ArrayList<>();
        for (Map.Entry<Integer, Long> entry : mp.entrySet()) {
            Long result = (long) (entry.getValue() * (entry.getValue() - 1)) / 2;
            arr.add(result);
        }
        Long total = (long) 0;
        for (long i : arr) {
            total += i;
        }
        long ans = 0;
        for (long i : arr) {
            total -= i;
            ans = (ans + (i * total) % Modd) % Modd;
        }
        return (int) ans;
    }
}