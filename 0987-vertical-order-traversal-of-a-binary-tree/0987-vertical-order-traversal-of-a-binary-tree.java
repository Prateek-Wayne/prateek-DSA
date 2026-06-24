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
  void helper(TreeNode root, int height, int level, TreeMap<Integer, TreeMap<Integer, List<Integer>>> mp) {
        if (root == null)
            return;
        mp.putIfAbsent(level, new TreeMap<>());
        mp.get(level).putIfAbsent(height, new ArrayList<>());
        mp.get(level).get(height).add(root.val);
        helper(root.left, height + 1, level - 1, mp);
        helper(root.right, height + 1, level + 1, mp);
    }

    public List<List<Integer>> verticalTraversal(TreeNode root) {
       TreeMap<Integer, TreeMap<Integer, List<Integer>>> mp = new TreeMap<>();

        helper(root, 0, 0, mp);
        List<List<Integer>> ans = new ArrayList<>();
        for (Integer i : mp.keySet()) {
            List<Integer> temp = new ArrayList<>();
            for (Integer j : mp.get(i).keySet()) {
                List<Integer> list = mp.get(i).get(j);
                list.sort(null);
                temp.addAll(list);
            }
            ans.add(temp);
        }
        return ans;
    }
}