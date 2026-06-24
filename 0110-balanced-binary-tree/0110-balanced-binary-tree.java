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
    public long helper(TreeNode root){
        if(root==null)
            return 0;
        long left= 1+helper(root.left);
        long right=1+helper(root.right);
        if(Math.abs(left-right)>1)
            return Integer.MAX_VALUE;
        return Math.max(left,right);
    }
    public boolean isBalanced(TreeNode root) {
        long ans=helper(root);
        if(ans>=Integer.MAX_VALUE)
            return false;
        return true;
    }
}