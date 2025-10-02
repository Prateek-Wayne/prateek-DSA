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
    int count = 0;

    void helper(TreeNode root) {
        if (root == null)
            return;
        count += 1;
        helper(root.left);
        helper(root.right);
    }

    int countNodes(TreeNode root) {
        // int count = 0;
        helper(root);
        return count;
    }
}