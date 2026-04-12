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
 void dfs(TreeNode root, int k, PriorityQueue<Integer> pq) {
        if (root == null)
            return;
        pq.add(root.val);
        if (pq.size() > k)
            pq.poll();
        dfs(root.left, k, pq);
        dfs(root.right, k, pq);
    }

    public int kthSmallest(TreeNode root, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        dfs(root, k, pq);
        return pq.size() > 0 ? pq.peek() : -1;
    }
}