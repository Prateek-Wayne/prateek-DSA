class Solution {
    public int digits(int x) {
        int cnt = 0;
        while(x > 0) {
            cnt++;
            x /= 10;
        }
        return cnt;
    }

    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        HashSet<Integer> prefixes =new HashSet<>();

        // storing all prefixes of arr1
        for(int num : arr1) {
            int x = num;
            while(x > 0) {
                prefixes.add(x);
                x /= 10;
            }
        }

        int ans = 0;

        // check prefixes of arr2 numbers
        for(int num : arr2) {
            int x = num;
            int len = digits(num);

            // checking from larger => smaller
            while(x > 0) {
                if(prefixes.contains(x)) {
                    ans = Math.max(ans, len);
                    // first match is the longest
                    // so we stop
                    break;
                }

                x /= 10;
                len--;
            }
        }

        return ans;
    }
}