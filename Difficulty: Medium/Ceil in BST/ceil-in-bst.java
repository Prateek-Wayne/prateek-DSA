/* class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        left = right = null;
    }
} */

class Solution {
    int findCeil(Node root, int x) {
        // code here
        int ans = Integer.MAX_VALUE;
        while (root != null) {
            if (root.data >= x) {
                ans = Math.min(ans, root.data);
                root = root.left;
            } else
                root = root.right;

        }
        return ans == Integer.MAX_VALUE ? -1 : ans;


    }
}