package LC523ContinuousSubarraySum;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class SolutionTest {
    private final Solution solution = new Solution();

    @Test
    void findMaxLength1() {
        int[] nums = {23, 2, 4, 6, 7};
        int k = 6;
        assertEquals(true, solution.checkSubarraySum(nums, k));
    }

    @Test
    void findMaxLength2() {
        int[] nums = {23, 2, 6, 4, 7};
        int k = 6;
        assertEquals(true, solution.checkSubarraySum(nums, k));
    }

    @Test
    void findMaxLength3() {
        int[] nums = {23, 2, 6, 4, 7};
        int k = 13;
        assertEquals(false, solution.checkSubarraySum(nums, k));
    }

    @Test
    void findMaxLength4() {
        int[] nums = {6};
        int k = 6;
        assertEquals(false, solution.checkSubarraySum(nums, k));
    }

    @Test
    void findMaxLength5() {
        int[] nums = {6, 1, 1, 1, 1, 1, 1};
        int k = 6;
        assertEquals(true, solution.checkSubarraySum(nums, k));
    }
}
