package LC130SurroundedRegions;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

public class SolutionTest {
    @Test
    void solve() {
        Solution solution = new Solution();
        char[][] board = new char[][]{
                {'X', 'X', 'X', 'X'},
                {'X', 'O', 'O', 'X'},
                {'X', 'X', 'O', 'X'},
                {'X', 'O', 'X', 'X'}
        };
        char[][] expected = new char[][]{
                {'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X'},
                {'X', 'O', 'X', 'X'}
        };
        solution.solve(board);
        for (int rowIndex = 0; rowIndex < board.length; rowIndex++) {
            assertArrayEquals(expected[rowIndex], board[rowIndex]);
        }
    }


    @Test
    void solve1() {
        Solution solution = new Solution();
        char[][] board = new char[][]{
                {'O', 'O', 'O' },
                {'O', 'O', 'O' },
                {'O', 'O', 'O' },
        };
        char[][] expected = new char[][]{
                {'O', 'O', 'O' },
                {'O', 'O', 'O' },
                {'O', 'O', 'O' },
        };
        solution.solve(board);
        for (int rowIndex = 0; rowIndex < board.length; rowIndex++) {
            assertArrayEquals(expected[rowIndex], board[rowIndex]);
        }
    }

    @Test
    void solve2() {
        Solution solution = new Solution();
        char[][] board = new char[][]{
                {'O', 'O', 'O', 'O', 'X', 'X'},
                {'O', 'O', 'O', 'O', 'O', 'O'},
                {'O', 'X', 'O', 'X', 'O', 'O'},
                {'O', 'X', 'O', 'O', 'X', 'O'},
                {'O', 'X', 'O', 'X', 'O', 'O'},
                {'O', 'X', 'O', 'O', 'O', 'O'},
        };
        char[][] expected = new char[][]{
                {'O', 'O', 'O', 'O', 'X', 'X'},
                {'O', 'O', 'O', 'O', 'O', 'O'},
                {'O', 'X', 'O', 'X', 'O', 'O'},
                {'O', 'X', 'O', 'O', 'X', 'O'},
                {'O', 'X', 'O', 'X', 'O', 'O'},
                {'O', 'X', 'O', 'O', 'O', 'O'}
        };
        solution.solve(board);
        for (int rowIndex = 0; rowIndex < board.length; rowIndex++) {
            assertArrayEquals(expected[rowIndex], board[rowIndex]);
        }
    }

    @Test
    void solve3() {
        Solution solution = new Solution();
        char[][] board = new char[][]{
                { 'O', 'X', 'O', 'O', 'O', 'X' },
                { 'O', 'O', 'X', 'X', 'X', 'O' },
                { 'X', 'X', 'X', 'X', 'X', 'O' },
                { 'O', 'O', 'O', 'O', 'X', 'X' },
                { 'X', 'X', 'O', 'O', 'X', 'O' },
                { 'O', 'O', 'X', 'X', 'X', 'X' },
        };
        char[][] expected = new char[][]{
                { 'O', 'X', 'O', 'O', 'O', 'X' },
                { 'O', 'O', 'X', 'X', 'X', 'O' },
                { 'X', 'X', 'X', 'X', 'X', 'O' },
                { 'O', 'O', 'O', 'O', 'X', 'X' },
                { 'X', 'X', 'O', 'O', 'X', 'O' },
                { 'O', 'O', 'X', 'X', 'X', 'X' },
        };
        solution.solve(board);
        for (int rowIndex = 0; rowIndex < board.length; rowIndex++) {
            assertArrayEquals(expected[rowIndex], board[rowIndex]);
        }
    }
}
