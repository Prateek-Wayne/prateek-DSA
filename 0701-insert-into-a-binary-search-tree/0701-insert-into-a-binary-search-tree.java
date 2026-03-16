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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        TreeNode temp = root;
        if (root == null)
            return new TreeNode(val);
        while (true) {
            if (temp.val < val) {
                if (temp.right != null)
                    temp = temp.right;
                else {
                    temp.right = new TreeNode(val);
                    break;
                }
            } else {
                if (temp.left != null)
                    temp = temp.left;
                else {
                    temp.left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
}