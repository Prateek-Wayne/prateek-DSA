class Solution {
     int n;

    public int dfs(int i,int[] arr,int d,int[] dp) {

        if(dp[i] != -1) {
            return dp[i];
        }

        int ans = 1;

        // move right
        for(int j = i + 1;j <= Math.min(n - 1, i + d);j++) {

            // blocked
            if(arr[j] >= arr[i]) {
                break;
            }

            ans = Math.max(ans,1 + dfs(j, arr, d, dp));
        }

        // move left
        for(int j = i - 1;j >= Math.max(0, i - d);j--) {

            // blocked
            if(arr[j] >= arr[i]) {
                break;
            }

            ans = Math.max(ans,1 + dfs(j, arr, d, dp));
        }

        return dp[i] = ans;
    }

    public int maxJumps(int[] arr, int d) {
        n = arr.length;

        int[] dp = new int[n];
        Arrays.fill(dp, -1);

        int ans = 1;

        for(int i = 0; i < n; i++) {
            ans = Math.max(ans,dfs(i, arr, d, dp));
        }

        return ans;
    }
}