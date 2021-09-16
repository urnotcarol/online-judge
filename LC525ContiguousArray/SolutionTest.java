package LC525ContiguousArray;

import static org.junit.jupiter.api.Assertions.assertEquals;
import org.junit.jupiter.api.Test;

public class SolutionTest {
    private final Solution solution = new Solution();

    @Test
    void findMaxLength1() {
        int[] nums = { 0, 1, 0 };
        assertEquals(2, solution.findMaxLength(nums));
    }

    @Test
    void findMaxLength2() {
        int[] nums = { 0, 1 };
        assertEquals(2, solution.findMaxLength(nums));
    }

    @Test
    void findMaxLength3() {
        int[] nums = { 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 };
        assertEquals(8, solution.findMaxLength(nums));
    }

    @Test
    void findMaxLength4() {
        int[] nums = { 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1 };
        assertEquals(18, solution.findMaxLength(nums));
    }
}
