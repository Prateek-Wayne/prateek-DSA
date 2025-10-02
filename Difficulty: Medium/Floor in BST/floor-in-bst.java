// User function Template for Java

class Solution {
  public static int floor(Node root, int x) {
        int ans = Integer.MIN_VALUE;
        // Code here
        while (root != null) {
            if (root.data <= x) {
                ans = Math.max(ans, root.data);
                root = root.right;
            } else
                root = root.left;
        }
        return ans == Integer.MIN_VALUE ? -1 : ans;
    }
}