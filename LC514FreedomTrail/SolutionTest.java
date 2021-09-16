package LC514FreedomTrail;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SolutionTest {
    private final Solution solution = new Solution();
    private final Solution2 solution2 = new Solution2();

    @Test
    void findRotateSteps() {
        String ring = "godding";
        String key = "gd";
        assertEquals(4, solution.findRotateSteps(ring, key));
        assertEquals(4, solution2.findRotateSteps(ring, key));
    }

    @Test
    void findRotateSteps1() {
        String ring = "godding";
        String key = "g";
        assertEquals(1, solution.findRotateSteps(ring, key));
        assertEquals(1, solution2.findRotateSteps(ring, key));
    }

    @Test
    void findRotateSteps2() {
        String ring = "godding";
        String key = "godding";
        assertEquals(13, solution.findRotateSteps(ring, key));
        assertEquals(13, solution2.findRotateSteps(ring, key));
    }

    @Test
    void findRotateSteps4() {
        String ring = "nyngl";
        String key = "yyynnnnnnlllggg";
        assertEquals(19, solution.findRotateSteps(ring, key));
        assertEquals(19, solution2.findRotateSteps(ring, key));
    }

    @Test
    void findRotateSteps5() {
        String ring = "bcdaef";
        String key = "bacdef";
        assertEquals(15, solution.findRotateSteps(ring, key));
        assertEquals(15, solution2.findRotateSteps(ring, key));
    }

    @Test
    void findRotateSteps6() {
        String ring = "aaaaa";
        String key = "aaaaa";
        assertEquals(5, solution.findRotateSteps(ring, key));
        assertEquals(5, solution2.findRotateSteps(ring, key));
    }

    @Test
    void findRotateSteps7() {
        String ring = "caotmcaataijjxi";
        String key = "oatjiio";
//        assertEquals(137, solution.findRotateSteps(ring, key));
        assertEquals(137, solution2.findRotateSteps(ring, key));
    }
}