class Solution {
    int[] parent;
    int[] rank;

    int find(int x, int[] parent) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x], parent);
    }

    void union(int x, int y, int[] parent, int[] rank) {
        int parentX = find(x, parent);
        int parentY = find(y, parent);
        if (parentX == parentY)
            return;
        if (rank[parentX] == rank[parentY]) {
            rank[parentX]++;
            parent[parentY] = parentX;
        } else if (rank[parentX] > rank[parentY]) {
            parent[parentY] = parentX;
        } else {
            parent[parentX] = parentY;
        }
        return;
    }

      public boolean equationsPossible(String[] equations) {
        if (parent == null) {
            parent = new int[26];
            for (int i = 0; i < 26; i++) {
                parent[i] = i;
            }
        }
        if (rank == null) {
            rank = new int[26];
        }
        for (String s : equations) {
            int c1 = s.charAt(0) - 'a';
            int c2 = s.charAt(3) - 'a';
            String operation = s.substring(1, 3);
            if (operation.equals("==")) {
                union(c1, c2, parent, rank);
            }
        }
        for (String s : equations) {
            int c1 = s.charAt(0) - 'a';
            int c2 = s.charAt(3) - 'a';
            String operation = s.substring(1, 3);
            if (operation.equals("!=")) {
                if (find(c1, parent) == find(c2, parent))
                    return false;
            }
        }
        return true;
    }
}