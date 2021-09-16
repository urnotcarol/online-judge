package LC199BinaryTreeRightSideView;

import common.TreeNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

public class SolutionTest {
    private final Solution solution = new Solution();

    @Test
    void rightSideView() {
        TreeNode one = new TreeNode(1);
        TreeNode three = new TreeNode(3);
        TreeNode two = new TreeNode(2, one, three);
        TreeNode six = new TreeNode(6);
        TreeNode root = new TreeNode(4, two, six);

        Integer[] expected = new Integer[]{ 4, 6, 3 };
        assertArrayEquals(expected, solution.rightSideView(root).toArray());
    }
}
