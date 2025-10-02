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
                    break;
                } else
                    temp = temp.left;
            } else {
                // move right;
                if (temp.right != null && temp.right.val == key) {
                    temp.right = helper(temp.right);
                    break;
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
        TreeNode leftNode = root.left;
        TreeNode rightNode = findLeftMostLeadNode(root.right);
        rightNode.left = leftNode;
        return root.right;
    }

    private TreeNode findLeftMostLeadNode(TreeNode root) {
        if (root.left == null)
            return root;
        return findLeftMostLeadNode(root.left);
    }
}