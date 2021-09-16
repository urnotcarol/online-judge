package LC113PathSumII;

import common.TreeNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class SolutionTest {
    private final Solution solution = new Solution();

    @Test
    void pathSum() {
        TreeNode one = new TreeNode(1);
        TreeNode three = new TreeNode(3);
        TreeNode two = new TreeNode(2, one, three);
        TreeNode six = new TreeNode(6);
        TreeNode root = new TreeNode(4, two, six);
        assertEquals("[[4, 2, 3]]", solution.pathSum(root, 9).toString());
    }
}
