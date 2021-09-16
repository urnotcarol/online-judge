package LC684RedundantConnection;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

public class SolutionTest {
    private final SolutionDFS solutionDFS = new SolutionDFS();
    private final Solution solution = new Solution();

    @Test
    void findRedundantConnection() {
        int[][] edges = new int[][]{
                {1, 2},
                {2, 3},
                {3, 4},
                {1, 4},
                {1, 5}
        };
        int[] result = new int[]{1, 4};
        assertArrayEquals(result, solutionDFS.findRedundantConnection(edges));
        assertArrayEquals(result, solution.findRedundantConnection(edges));
    }

    @Test
    void findRedundantConnection2() {
        int[][] edges = new int[][]{
                {1, 2},
                {1, 3},
                {2, 3},
        };
        int[] result = new int[]{2, 3};
        assertArrayEquals(result, solutionDFS.findRedundantConnection(edges));
        assertArrayEquals(result, solution.findRedundantConnection(edges));
    }

    @Test
    void findRedundantConnection3() {
        int[][] edges = new int[][]{
                {1, 2},
                {1, 5},
                {1, 6},
                {2, 3},
                {3, 4},
                {5, 6},
        };
        int[] result = new int[]{5, 6};
        assertArrayEquals(result, solutionDFS.findRedundantConnection(edges));
        assertArrayEquals(result, solution.findRedundantConnection(edges));
    }

    @Test
    void findRedundantConnection4() {
        int[][] edges = new int[][]{
                {1, 2},
                {1, 3},
                {2, 4},
                {2, 5},
                {4, 6},
                {3, 6},
        };
        int[] result = new int[]{3, 6};
        assertArrayEquals(result, solutionDFS.findRedundantConnection(edges));
        assertArrayEquals(result, solution.findRedundantConnection(edges));
    }

    @Test
    void findRedundantConnection5() {
        int[][] edges = new int[][]{
                {2,7},
                {7,8},
                {3,6},
                {2,5},
                {6,8},
                {4,8},
                {2,8},
                {1,8},
                {7,10},
                {3,9},
        };
        int[] result = new int[]{2,8};
        assertArrayEquals(result, solutionDFS.findRedundantConnection(edges));
        assertArrayEquals(result, solution.findRedundantConnection(edges));
    }

    @Test
    void findRedundantConnection6() {
        int[][] edges = new int[][]{
                {2,3},
                {3,4},
                {4,2},
                {1,2},
        };
        int[] result = new int[]{4,2};
        assertArrayEquals(result, solutionDFS.findRedundantConnection(edges));
        assertArrayEquals(result, solution.findRedundantConnection(edges));
    }
}
