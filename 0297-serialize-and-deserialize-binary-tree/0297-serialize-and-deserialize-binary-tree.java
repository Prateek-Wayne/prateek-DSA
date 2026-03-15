/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
public String serialize(TreeNode root) {

    if (root == null)
        return "";

    String ans = "";
    Queue<TreeNode> q = new LinkedList<>();
    q.add(root);

    while (!q.isEmpty()) {

        int size = q.size();

        while (size-- > 0) {

            TreeNode top = q.poll();

            if (top == null) {
                ans += "# ";
                continue;
            }

            ans += top.val + " ";

            q.add(top.left);
            q.add(top.right);
        }
    }

    return ans;
}

   public TreeNode deserialize(String data) {

    if (data.equals(""))
        return null;

    String[] arr = data.trim().split(" ");

    TreeNode root = new TreeNode(Integer.parseInt(arr[0]));

    Queue<TreeNode> q = new LinkedList<>();
    q.add(root);

    int i = 1;

    while (!q.isEmpty()) {

        TreeNode top = q.poll();

        if (!arr[i].equals("#")) {
            top.left = new TreeNode(Integer.parseInt(arr[i]));
            q.add(top.left);
        }

        i++;

        if (!arr[i].equals("#")) {
            top.right = new TreeNode(Integer.parseInt(arr[i]));
            q.add(top.right);
        }

        i++;
    }

    return root;
}
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));