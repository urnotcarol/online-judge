package LC124BinaryTreeMaximumPathSum;

import common.TreeNode;

class Solution {
    private double localMaxSum = Double.NEGATIVE_INFINITY;

    private int traversalPost(TreeNode node) {
        if (node == null) {
            return 0;
        }

        int leftSum = traversalPost(node.left);
        int rightSum = traversalPost(node.right);

        updateMaxLocal(node.val);
        updateMaxLocal(node.val + leftSum + rightSum);
        updateMaxLocal(node.val + Math.max(leftSum, rightSum));

        return node.val + Math.max(0, Math.max(leftSum, rightSum));
    }

    private void updateMaxLocal(int number) {
        localMaxSum = Math.max(localMaxSum, number);
    }

    public int maxPathSum(TreeNode root) {
        return Math.max(traversalPost(root), (int)localMaxSum);
    }
}
