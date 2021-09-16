package LC72EditDistance;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class SolutionTest {
    private final SolutionDFS solutionDFS = new SolutionDFS();
    private final Solution solution = new Solution();

    @Test
    void TestFindMinDistance() {
        assertEquals(2, solutionDFS.minDistance("console", "onsolec"));
        assertEquals(2, solution.minDistance("console", "onsolec"));
    }

    @Test
    void TestFindMinDistance1() {
        assertEquals(5, solutionDFS.minDistance("intention", "execution"));
        assertEquals(5, solution.minDistance("intention", "execution"));
    }

    @Test
    void TestFindMinDistance2() {
        assertEquals(3, solutionDFS.minDistance("teacher", "apache"));
        assertEquals(3, solution.minDistance("teacher", "apache"));
    }

    @Test
    void TestFindMinDistance3() {
        assertEquals(7, solutionDFS.minDistance("dinitrophenylhydrazine", "dimethylhydrazine"));
        assertEquals(7, solution.minDistance("dinitrophenylhydrazine", "dimethylhydrazine"));
    }

    @Test
    void TestFindMinDistance4() {
        assertEquals(2, solution.minDistance("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdef",
                "bcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefg"));
    }

    @Test
    void TestFindMinDistance5() {
        assertEquals(27, solution.minDistance("pneumonoultramicroscopicsilicovolcanoconiosis",
                "ultramicroscopically"));
    }

    @Test
    void TestFindMinDistance6() {
        assertEquals(1, solution.minDistance("", "a"));
    }

    @Test
    void TestFindMinDistance7() {
        assertEquals(2, solution.minDistance("pap", "p"));
    }
}
