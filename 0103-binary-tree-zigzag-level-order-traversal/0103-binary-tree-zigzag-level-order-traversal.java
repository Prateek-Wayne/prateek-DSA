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
 public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null)
            return ans;
        Queue<TreeNode> q = new LinkedList<>();
        boolean leftToright = true;
        q.add(root);
        while (!q.isEmpty()) {
            int size = q.size();
            List<Integer> ds = new ArrayList<>();
            while (size != 0) {
                TreeNode top = q.poll();
                ds.add(top.val);
                if (top.left != null)
                    q.add(top.left);
                if (top.right != null)
                    q.add(top.right);
                size--;
            }
            if (leftToright) {
                ans.add(ds);
            } else {
                ans.add(ds.reversed());
            }
            leftToright = !leftToright;
        }
        return ans;
    }
}