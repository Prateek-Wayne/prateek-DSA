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
    int helper(TreeNode root,int[] diameter){
        if(root==null)
            return 0;
        int left=helper(root.left,diameter);
        int right=helper(root.right,diameter);
        diameter[0]=Math.max(diameter[0],left+right);
        return 1+Math.max(left,right);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        int[] diameter=new int[]{0};
        int temp=helper(root,diameter);
        return diameter[0];
    }
}