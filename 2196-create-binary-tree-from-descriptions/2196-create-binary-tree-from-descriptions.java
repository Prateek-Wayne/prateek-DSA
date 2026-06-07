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
    public TreeNode createBinaryTree(int[][] descriptions) {
        HashMap<Integer, TreeNode> mp = new HashMap<>();
        Set<Integer> childSet = new HashSet<>();
        for (int[] desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];
            mp.putIfAbsent(parent, new TreeNode(parent));
            mp.putIfAbsent(child, new TreeNode(child));
            TreeNode parentNode = mp.get(parent);
            TreeNode childNode = mp.get(child);
            if (isLeft==1) {
                parentNode.left = childNode;
            } else
                parentNode.right = childNode;
            childSet.add(child);
        }
        for (int[] desc : descriptions) {
            int parent = desc[0];
            if (!childSet.contains(parent))
                return mp.get(parent);
        }
        return null;

    }
}