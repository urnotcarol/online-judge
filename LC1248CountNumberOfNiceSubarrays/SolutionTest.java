package LC1248CountNumberOfNiceSubarrays;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class SolutionTest {
    private final Solution solution = new Solution();

    @Test
    void numberOfSubarrays1() {
        int nums[] = {1, 1, 2, 1, 1};
        int k = 3;
        assertEquals(2, solution.numberOfSubarrays(nums, k));
    }

    @Test
    void numberOfSubarrays2() {
        int nums[] = {2, 4, 6};
        int k = 1;
        assertEquals(0, solution.numberOfSubarrays(nums, k));
    }

    @Test
    void numberOfSubarrays3() {
        int nums[] = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
        int k = 2;
        assertEquals(16, solution.numberOfSubarrays(nums, k));
    }

    @Test
    void numberOfSubarrays4() {
        int nums[] = {2, 2, 2, 1, 2, 1};
        int k = 2;
        assertEquals(4, solution.numberOfSubarrays(nums, k));
    }

    @Test
    void numberOfSubarrays5() {
        int nums[] = {2, 2, 2, 1, 2, 1, 1};
        int k = 2;
        assertEquals(6, solution.numberOfSubarrays(nums, k));
    }
}
