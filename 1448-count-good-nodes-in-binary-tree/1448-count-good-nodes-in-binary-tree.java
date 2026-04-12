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
 void dfs(TreeNode root, int[] count, PriorityQueue<Integer> pq) {
        if (root == null)
            return;
        pq.add(root.val);
        if (pq.peek() <= root.val)
            count[0]++;
        dfs(root.left, count, pq);
        dfs(root.right, count, pq);
        pq.remove(root.val);
    }

    public int goodNodes(TreeNode root) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        int[] count = new int[] { 0 };
        dfs(root, count, pq);
        return count[0];
    }
}