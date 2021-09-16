package LC99RecoverBinarySearchTree;

import common.TreeNode;

class Solution {
    private TreeNode prevNode;
    private TreeNode leftWrongNode;
    private TreeNode rightWrongNode;

    private void traversalInRe(TreeNode node) {
        if (node == null) {
            return;
        }
        traversalInRe(node.left);
        if (prevNode != null) {
            if (node.val < prevNode.val) {
                if (leftWrongNode == null) {
                    leftWrongNode = prevNode;
                }
                rightWrongNode = node;
            }
        }
        prevNode = node;
        traversalInRe(node.right);
    }

    public void recoverTree(TreeNode root) {
        traversalInRe(root);
        int temp = leftWrongNode.val;
        leftWrongNode.val = rightWrongNode.val;
        rightWrongNode.val = temp;
    }
}
