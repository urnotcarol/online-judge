package LC130SurroundedRegions;

class Solution {
    private int rowSize = 0;
    private int colSize = 0;
    boolean[][] coloredO;
    boolean[][] visited;

    private boolean isEdge(int x, int y) {
        return x == 0 || y == 0 || x == rowSize - 1 || y == colSize - 1;
    }

    private void colorNearO(char[][] board, int x, int y) {
        if (x < 0 || y < 0 || x >= rowSize || y >= colSize) {
            return;
        }
        if (visited[x][y]) {
            return;
        }

        visited[x][y] = true;
        if (board[x][y] == 'O') {
            coloredO[x][y] = true;
            colorNearO(board, x - 1, y);
            colorNearO(board, x, y + 1);
            colorNearO(board, x + 1, y);
            colorNearO(board, x, y - 1);
        }
    }

    public void solve(char[][] board) {
        rowSize = board.length;
        colSize = board[0].length;

        coloredO = new boolean[rowSize][colSize];
        visited = new boolean[rowSize][colSize];

        for (int x = 0; x < rowSize; x++) {
            for (int y = 0; y < colSize; y++) {
                if (isEdge(x, y)) {
                    colorNearO(board, x, y);
                }
            }
        }

        for (int x = 0; x < rowSize; x++) {
            for (int y = 0; y < colSize; y++) {
                if (board[x][y] == 'O' && !coloredO[x][y]) {
                    board[x][y] = 'X';
                }
            }
        }
    }
}
