package LC114FlattenBinaryTreeToLinkedList;

import common.TreeNode;

class Solution {
    public void flatten(TreeNode root) {
        TreeNode node = root;
        while (node != null) {
            if (node.left != null) {
                TreeNode predecessor = node.left;
                while (predecessor.right != null) {
                    predecessor = predecessor.right;
                }
                predecessor.right = node.right;
                node.right = node.left;
                node.left = null;
            }
            node = node.right;
        }
    }
}