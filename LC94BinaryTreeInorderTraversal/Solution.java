package LC94BinaryTreeInorderTraversal;
import common.TreeNode;

import java.util.ArrayList;
import java.util.List;

class Solution {
    private void traversalIn(TreeNode node, ArrayList<Integer> visited) {
        if (node == null) {
            return;
        }
        traversalIn(node.left, visited);
        visited.add(node.val);
        traversalIn(node.right, visited);
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> list = new ArrayList<>();
        traversalIn(root, list);
        return list;
    }
}
