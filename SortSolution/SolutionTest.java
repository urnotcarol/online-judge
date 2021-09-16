package SortSolution;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

public class SolutionTest {
    private final Solution solution = new Solution();

    @Test
    void quickSort() {
        int[] input = new int[]{ 1, 3, 2, 4, 5 };
        int[] expected = new int[]{ 1, 2, 3, 4, 5 };
        assertArrayEquals(expected, solution.quickSort(input));
    }
}
