package LC454FourSumII;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class SolutionTest {
    private final Solution solution = new Solution();

    @Test
    void fourSumCount() {
        int[] nums1 = {1, 2};
        int[] nums2 = new int[]{-2, -1};
        int[] nums3 = {-1, 2};
        int[] nums4 = {0, 2};
        assertEquals(2, solution.fourSumCount(nums1, nums2, nums3, nums4));
    }

    @Test
    void fourSumCount1() {
        int[] nums1 = {1, 2, 100};
        int[] nums2 = {-2, -1, -50};
        int[] nums3 = {-1, 2, -50};
        int[] nums4 = {0, 2, 0};
        assertEquals(5, solution.fourSumCount(nums1, nums2, nums3, nums4));
    }

    @Test
    void fourSumCount2() {
        int[] nums1 = {1, 2, 3}; // 4： 3
        int[] nums2 = {3, 2, 1};
        int[] nums3 = {-1, -2, -3}; // -4：3
        int[] nums4 = {-3, -2, -1};
        assertEquals(19, solution.fourSumCount(nums1, nums2, nums3, nums4));
    }
}
