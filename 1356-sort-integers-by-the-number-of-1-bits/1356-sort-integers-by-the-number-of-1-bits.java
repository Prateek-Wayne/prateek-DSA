class Pair {
    int first;
    int second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Solution {
    public int calculateBits(int n) {
        int count = 0;
        while (n != 0)  {
            count += (n & 1);
            n = n >> 1;
        }
        return count;
    }

    public int[] sortByBits(int[] arr) {
        List<Pair> list = new ArrayList<>();
        for (int i : arr) {
            int bitsCount = calculateBits(i);
            Pair temp = new Pair(bitsCount, i);
            list.add(temp);
        }

        list.sort((a, b) -> {
            if (a.first == b.first) {
                return a.second - b.second;
            }
            return a.first - b.first;
        });

        int[] ans = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            ans[i] = list.get(i).second;
        }
        return ans;
    }
}