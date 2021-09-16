package LC99RecoverBinarySearchTree;

import common.TreeNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class SolutionTest {
    private final Solution solution = new Solution();
    private final LC98ValidateBinarySearchTree.Solution validateSolution = new LC98ValidateBinarySearchTree.Solution();

    @Test
    void recoverTree() {
        TreeNode one = new TreeNode(4);
        TreeNode three = new TreeNode(3);
        TreeNode two = new TreeNode(2, one, three);
        TreeNode six = new TreeNode(6);
        TreeNode root = new TreeNode(1, two, six);
        assertFalse(validateSolution.isValidBST(root));
        solution.recoverTree(root);
        assertTrue(validateSolution.isValidBST(root));
    }
}
