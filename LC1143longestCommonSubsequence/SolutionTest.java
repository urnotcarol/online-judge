package LC1143longestCommonSubsequence;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class SolutionTest {
    private final Solution solution = new Solution();
    private final SolutionDFS solutionDFS = new SolutionDFS();

    @Test
    void TestFindMinDistance() {
        assertEquals(3, solution.longestCommonSubsequence("abcde", "ace"));
        assertEquals(3, solutionDFS.longestCommonSubsequence("abcde", "ace"));
    }

    @Test
    void TestFindMinDistance2() {
        assertEquals(4, solution.longestCommonSubsequence("teacher", "apache"));
        assertEquals(4, solutionDFS.longestCommonSubsequence("teacher", "apache"));
    }

    @Test
    void TestFindMinDistance3() {
        assertEquals(15, solution.longestCommonSubsequence("dinitrophenylhydrazine", "dimethylhydrazine"));
        assertEquals(15, solutionDFS.longestCommonSubsequence("dinitrophenylhydrazine", "dimethylhydrazine"));
    }
}
