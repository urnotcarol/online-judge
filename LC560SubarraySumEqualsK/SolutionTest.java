package LC560SubarraySumEqualsK;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class SolutionTest {
    private final Solution solution = new Solution();

    @Test
    void subarraySum() {
        int nums[] = {1, 1, 1};
        int k = 2;
        assertEquals(2, solution.subarraySum(nums, k));
    }

    @Test
    void subarraySum2() {
        int nums[] = {1, 2, 3};
        int k = 3;
        assertEquals(2, solution.subarraySum(nums, k));
    }

    @Test
    void subarraySum3() {
        int nums[] = {1, 2, 3, 1, 1, 1, 2, 1, -1, 1, 1, 1, 1};
        int k = 3;
        assertEquals(11, solution.subarraySum(nums, k));
    }
}
