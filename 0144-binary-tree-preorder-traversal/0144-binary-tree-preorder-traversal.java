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
 public List<Integer> preorderTraversal(TreeNode root) {
        Stack<TreeNode> st = new Stack<>();
        List<Integer> ans = new ArrayList<>();
        if (root == null)
            return ans;
        st.add(root);

        while (!st.isEmpty()) {
            TreeNode top = st.pop();
            ans.add(top.val);
            if (top.right != null)
                st.add(top.right);
            if (top.left != null) {
                st.add(top.left);
            }
        }
        return ans;
    }
}