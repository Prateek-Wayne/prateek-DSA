/*
class Node
{
    int data;
    Node left, right;

    public Node(int d)
    {
        data = d;
        left = right = null;
    }
}
*/

class Solution {
 void leftTraversal(Node root, ArrayList<Integer> ans) {
        if (root == null || (root.left == null && root.right == null))
            return;
        ans.add(root.data);
        if (root.left != null)
            leftTraversal(root.left, ans);
        else if (root.right != null)
            leftTraversal(root.right, ans);
    }

    void rightTraversal(Node root, ArrayList<Integer> ans) {
        if (root == null || (root.left == null && root.right == null))
            return;
        if (root.right != null)
            rightTraversal(root.right, ans);
        else if (root.left != null)
            rightTraversal(root.left, ans);
        ans.add(root.data);

    }

    void leafTraversal(Node root, ArrayList<Integer> ans) {
        if (root == null)
            return;
        if (root.left == null && root.right == null)
            ans.add(root.data);
        leafTraversal(root.left, ans);
        leafTraversal(root.right, ans);

    }

    ArrayList<Integer> boundaryTraversal(Node node) {
        // code here
        ArrayList<Integer> ans = new ArrayList<>();
        if (node == null)
            return ans;
        ans.add(node.data);
        leftTraversal(node.left, ans);
        leafTraversal(node.left, ans);
        leafTraversal(node.right, ans);
        rightTraversal(node.right, ans);
        return ans;

    }
}