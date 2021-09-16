package LC684RedundantConnection;

import java.util.HashMap;

class Solution {
    private final HashMap<Integer, Integer> par = new HashMap<>();
    private final HashMap<Integer, Integer> rank = new HashMap<>();

    private int find(int n) {
        if (par.get(n) == null) {
            par.put(n, n);
            rank.put(n, 0);
            return n;
        }
        if (par.get(n) == n) {
            return n;
        }
        return find(par.get(n));
    }

    private void unite(int x, int y) {
        int xPar = find(x);
        int yPar = find(y);
        if (xPar == yPar) {
            return;
        }

        int xRank = rank.get(xPar);
        int yRank = rank.get(yPar);
        if (xRank < yRank) {
            par.put(xPar, yPar);
        } else {
            par.put(yPar, xPar);
            if (xRank == yRank) {
                rank.put(xPar, xRank + 1);
            }
        }
    }

    private boolean same(int x, int y) {
        return find(x) == find(y);
    }

    public int[] findRedundantConnection(int[][] edges) {
        int[] res = new int[]{};
        for (int[] edge : edges) {
            if (same(edge[0], edge[1])) {
                res = edge;
                break;
            }
            unite(edge[0], edge[1]);
        }

        return res;
    }
}
