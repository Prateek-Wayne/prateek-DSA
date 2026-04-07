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
    int helper(TreeNode root,int[] height){
        if(root==null)
            return 0;
        int left=helper(root.left,height);
        int right=helper(root.right,height);
        if(Math.abs(left-right)>1)
            height[0]=Integer.MAX_VALUE;
        return 1+Math.max(left,right);
    }

    public boolean isBalanced(TreeNode root) {
        if(root==null)
            return true;
        int[] height=new int[]{0};
        helper(root,height);
        return height[0]==Integer.MAX_VALUE?false:true;
    }   
}