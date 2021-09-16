package LC98ValidateBinarySearchTree;

import common.TreeNode;

import java.util.Stack;

public class Solution {
    private void visitNode(TreeNode node, Stack<TreeNode> stack) {
        TreeNode cur = node;
        while (cur != null) {
            stack.push(cur);
            cur = cur.left;
        }
    }

    public boolean isValidBST(TreeNode root) {
        double prevValue = Double.NEGATIVE_INFINITY;

        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        visitNode(root.left, stack);
        while (!stack.isEmpty()) {
            TreeNode poppedNode = stack.pop();
            if (poppedNode.val <= prevValue) {
                return false;
            }
            prevValue = poppedNode.val;

            if (poppedNode.right != null) {
                visitNode(poppedNode.right, stack);
            }
        }
        return true;
    }
}
