/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
 int dfs(TreeNode root, int maxy) {
        if (root == null)
            return 0;
        int count = 0;
        if (root.val >= maxy) {
            count = 1;
            maxy = root.val;
        }
        count += dfs(root.left, maxy);
        count += dfs(root.right, maxy);
        return count;
    }

    public int goodNodes(TreeNode root) {
        return dfs(root, Integer.MIN_VALUE);
    }
}