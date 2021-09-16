package LC114FlattenBinaryTreeToLinkedList;

import common.TreeNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class SolutionTest {
    private final Solution solution = new Solution();

    @Test
    void flatten() {
        TreeNode one = new TreeNode(1);
        TreeNode three = new TreeNode(3);
        TreeNode two = new TreeNode(2, one, three);
        TreeNode six = new TreeNode(6);
        TreeNode root = new TreeNode(4, two, six);

        solution.flatten(root);

        assertEquals(null, root.right);
        assertEquals(two, root.right);

        assertEquals(null, two.left);
        assertEquals(one, two.right);

        assertEquals(null, one.left);
        assertEquals(three, one.right);

        assertEquals(null, three.left);
        assertEquals(six, three.right);

        assertEquals(null, six.left);
        assertEquals(null, six.right);
    }
}
