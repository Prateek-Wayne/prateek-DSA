class Solution {
    public int xorAfterQueries(int[] nums, int[][] queries) {
        int sqr = (int)Math.sqrt(nums.length);
        List<int[]>[] buckets = new List[sqr + 1];
        long[] vals = new long[nums.length];
        long mod = (long)Math.pow(10, 9) + 7;
        Arrays.fill(vals, 1);

        for (int[] q : queries){

            if (q[2] < sqr){
                if (buckets[q[2]] == null) buckets[q[2]] = new ArrayList<>();
                buckets[q[2]].add(q);
                continue;
            }

            for (int i = q[0]; i <= q[1]; i += q[2]){
                vals[i] *= q[3];
                vals[i] %= mod;
            }

        }

        for (int i = 1; i < buckets.length; i++){
            if (buckets[i] == null) continue;

            PriorityQueue<int[]> starts = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
            PriorityQueue<int[]> ends = new PriorityQueue<>((a, b) -> Integer.compare(a[1], b[1]));

            long[] periodProduct = new long[i];
            Arrays.fill(periodProduct, 1);

            for (int[] e : buckets[i]) starts.offer(e);

            for (int ind = 0; ind < nums.length; ind++){

                while (starts.size() != 0 && starts.peek()[0] == ind){
                    int[] q = starts.poll();
                    periodProduct[ind % i] *= q[3];
                    periodProduct[ind % i] %= mod;
                    ends.offer(q);
                }

                while (ends.size() != 0 && ends.peek()[1] < ind){
                    int[] q = ends.poll();
                    periodProduct[q[0] % i] *= modPow(q[3], mod - 2, mod);
                    periodProduct[q[0] % i] %= mod;
                }
               
                vals[ind] *= periodProduct[ind % i];
                vals[ind] %= mod;
            }
        }

        int res = 0;
        for (int i = 0; i < nums.length; i++){
            res ^= (int)((vals[i] * nums[i]) % mod);
        }

        return res;
    }

    private long modPow(long b, long e, long mod){
        long i = 1;

        while (e > 0){
            if (e % 2 == 1){
                i *= b;
                i %= mod;
            }

            b *= b;
            b %= mod;
            e >>= 1;
        }

        return i;
    }
}