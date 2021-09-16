package LC300LongestIncreasingSubsequence;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class SolutionTest {
    private final Solution solution = new Solution();

    @Test
    void testLengthOfLIS() {
        int[] input = new int[]{10, 9, 2, 5, 3, 7, 101, 18};
        assertEquals(4, solution.lengthOfLIS(input));
    }

    @Test
    void testLengthOfLIS2() {
        int[] input = new int[]{0, 1, 0, 3, 2, 3};
        assertEquals(4, solution.lengthOfLIS(input));
    }

    @Test
    void testLengthOfLIS3() {
        int[] input = new int[]{7, 7, 7, 7, 7, 7, 7};
        assertEquals(1, solution.lengthOfLIS(input));
    }
}
