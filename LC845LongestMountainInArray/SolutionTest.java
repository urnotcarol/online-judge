package LC845LongestMountainInArray;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class SolutionTest {
    private final Solution solution = new Solution();

    @Test
    void longestMountain() {
        int nums1[] = {2, 1, 4, 7, 3, 2, 5};
        assertEquals(5, solution.longestMountain(nums1));
    }

    @Test
    void longestMountain1() {
        int nums1[] = {2, 2, 2};
        assertEquals(0, solution.longestMountain(nums1));
    }

    @Test
    void longestMountain2() {
        int nums1[] = {2, 2, 2, 3, 2};
        assertEquals(3, solution.longestMountain(nums1));
    }

    @Test
    void longestMountain3() {
        int nums1[] = {2, 2, 2, 3, 2, 2, 2, 5, 4, 3, 2, 1};
        assertEquals(6, solution.longestMountain(nums1));
    }

    @Test
    void longestMountain4() {
        int nums1[] = {0,2,0,2,1,2,3,4,4,1};
        assertEquals(3, solution.longestMountain(nums1));
    }
}
