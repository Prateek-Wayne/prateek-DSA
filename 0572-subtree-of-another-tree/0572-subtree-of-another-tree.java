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
 void traverse(TreeNode root, TreeNode subRoot, List<TreeNode> nodes) {
        if (root == null)
            return;
        traverse(root.left, subRoot, nodes);
        if (root.val == subRoot.val)
            nodes.add(root);
        traverse(root.right, subRoot, nodes);

    }

    boolean checkIsSubTree(TreeNode root, TreeNode subRoot) {
        if (root == null && subRoot == null)
            return true;
        if (root == null || subRoot == null)
            return false;
        if (root.val != subRoot.val)
            return false;
        return checkIsSubTree(root.left, subRoot.left) && checkIsSubTree(root.right, subRoot.right);
    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        List<TreeNode> nodes = new ArrayList<>();
        traverse(root, subRoot, nodes);
        for (TreeNode i : nodes) {
            if (checkIsSubTree(i, subRoot) == true)
                return true;
        }
        return false;
    }
}