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
    String serialise(TreeNode root) {
        if (root == null) {
            return "#";
        }
        return "," + root.val + "," + serialise(root.left) + "," + serialise(root.right);
    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        String s1 = serialise(root);
        String s2 = serialise(subRoot);
        return s1.contains(s2);
    }
}