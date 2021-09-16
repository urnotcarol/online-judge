package LC124BinaryTreeMaximumPathSum;

import common.TreeNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class SolutionTest {
    private final Solution solution = new Solution();

    @Test
    void maxPathSum() {
        TreeNode one = new TreeNode(1);
        TreeNode three = new TreeNode(3);
        TreeNode two = new TreeNode(2, one, three);
        TreeNode six = new TreeNode(6);
        TreeNode root = new TreeNode(4, two, six);

        assertEquals(15, solution.maxPathSum(root));
    }

    @Test
    void MaxPathSum2() {
        TreeNode node8 = new TreeNode(8);
        TreeNode node9 = new TreeNode(9);
        node9.right = node8;

        TreeNode node20 = new TreeNode(20);
        TreeNode node10 = new TreeNode(10);
        node10.left = node9;
        node10.right = node20;

        TreeNode node15 = new TreeNode(15);
        TreeNode node22 = new TreeNode(22);
        TreeNode node28 = new TreeNode(28);
        node15.left = node22;
        node15.right = node28;

        node20.left = node15;
        TreeNode node7 = new TreeNode(7);
        node20.right = node7;

        assertEquals(90, solution.maxPathSum(node10));
    }

    @Test
    void MaxPathSum3() {
        TreeNode node8 = new TreeNode(8);
        TreeNode node20 = new TreeNode(20);
        TreeNode node10N = new TreeNode(-10);
        node8.left = node20;
        node8.right = node10N;

        TreeNode node200 = new TreeNode(200);
        node10N.right = node200;

        assertEquals(218, solution.maxPathSum(node8));
    }


    @Test
    void MaxPathSum4() {
        TreeNode node200N = new TreeNode(-200);
        TreeNode node400N = new TreeNode(-400);
        node200N.right = node400N;

        assertEquals(-200, solution.maxPathSum(node200N));
    }

    @Test
    void MaxPathSum5() {
        TreeNode node200N = new TreeNode(-200);
        TreeNode node400N = new TreeNode(-400);
        TreeNode node900N = new TreeNode(-900);
        node200N.right = node400N;
        node200N.left = node900N;

        assertEquals(-200, solution.maxPathSum(node200N));
    }

    @Test
    void maxPathSum6() {
        TreeNode node1N = new TreeNode(-1);
        TreeNode node9 = new TreeNode(9);
        node1N.right = node9;

        TreeNode node6N = new TreeNode(-6);
        TreeNode node3 = new TreeNode(3);
        node9.left = node6N;
        node9.right = node3;

        TreeNode node2N = new TreeNode(-2);
        node3.right = node2N;

        assertEquals(12, solution.maxPathSum(node1N));
    }
}
