package LC200NumberOfIslands;

class Solution {
    private int rowSize;
    private int colSize;

    private void markIsland(char[][] grid, int x, int y) {
        if (x < 0 || y < 0 || x >= rowSize || y >= colSize) {
            return;
        }
        if (grid[x][y] != '1') {
            return;
        }
        grid[x][y] = '2';
        markIsland(grid, x, y + 1);
        markIsland(grid, x, y - 1);
        markIsland(grid, x + 1, y);
        markIsland(grid, x - 1, y);
    }

    public int numIslands(char[][] grid) {
        rowSize = grid.length;
        if (rowSize < 1) {
            return 0;
        }
        colSize = grid[0].length;
        int num = 0;
        for (int x = 0; x < rowSize; x++) {
            for (int y = 0; y < colSize; y++) {
                if (grid[x][y] == '1') {
                    num++;
                    markIsland(grid, x, y);
                }
            }
        }
        return num;
    }
}
