/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
 void dfs(Node node, Node clone, Map<Node, Node> mp) {

        for (Node n : node.neighbors) {
            if (!mp.containsKey(n)) {
                Node newClone = new Node(n.val);
                mp.put(n, newClone);
                clone.neighbors.add(newClone);
                dfs(n, newClone, mp);
            } else {
                Node nClone = mp.get(n);
                clone.neighbors.add(nClone);
            }
        }
    }

    public Node cloneGraph(Node node) {
        Map<Node, Node> mp = new HashMap<>();
        if (node == null)
            return node;
        Node clone = new Node(node.val);
        mp.put(node, clone);
        dfs(node, clone, mp);
        return clone;
    }
}