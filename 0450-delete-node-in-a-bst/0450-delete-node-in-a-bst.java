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
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null)
            return root;
        if (root.val == key)
            return helper(root);
        TreeNode temp = root;
        while (temp != null) {
            // deciding where to search
            if (temp.val > key) {
                // move left;
                if (temp.left != null && temp.left.val == key) {
                    temp.left = helper(temp.left);
                } else
                    temp = temp.left;
            } else {
                // move right;
                if (temp.right != null && temp.right.val == key) {
                    temp.right = helper(temp.right);
                } else
                    temp = temp.right;
            }
        }
        return root;

    }

    TreeNode helper(TreeNode root) {
        if (root.left == null)
            return root.right;
        else if (root.right == null)
            return root.left;
        TreeNode rightNode = root.right;
        TreeNode lastRightNode = lastRightNodeFinder(root.left);
        lastRightNode.right = rightNode;
        return root.left;
    }

    private TreeNode lastRightNodeFinder(TreeNode root) {
        if (root.right == null)
            return root;
        return lastRightNodeFinder(root.right);

    }
}