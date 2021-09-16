package LC329LongestIncreasingPathInAMatrix;

class Solution {
    private int rowSize;
    private int colSize;
    private int[][] longestPathMemo;

    private int getVal(int i, int j, int[][] matrix) {
        return (i >= 0 && j >= 0 && i < rowSize && j < colSize) ? matrix[i][j] : -1;
    }

    private int dfs(int i, int j, int[][] matrix, int prevVal) {
        int val = getVal(i, j, matrix);
        if (val == -1) {
            return 0;
        }
        if (val <= prevVal) {
            return 0;
        }
        if (longestPathMemo[i][j] > 0) {
            return longestPathMemo[i][j];
        }

        int max = 0;
        max = dfs(i, j + 1, matrix, val);
        max = Math.max(max, dfs(i - 1, j, matrix, val));
        max = Math.max(max, dfs(i, j - 1, matrix, val));
        max = Math.max(max, dfs(i + 1, j, matrix, val));
        longestPathMemo[i][j] = max + 1;
        return longestPathMemo[i][j];
    }

    public int longestIncreasingPath(int[][] matrix) {
        rowSize = matrix.length;
        colSize = rowSize > 0 ? matrix[0].length : 0;
        longestPathMemo = new int[rowSize][colSize];

        int max = 0;
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                max = Math.max(max, dfs(i, j, matrix, -1));
            }
        }
        return max;
    }
}
