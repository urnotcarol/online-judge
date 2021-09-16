package LC199BinaryTreeRightSideView;

import common.TreeNode;

import java.util.ArrayList;
import java.util.List;

class Solution {
    private final ArrayList<Integer> rightSizeList = new ArrayList<>();

    private void dfs(TreeNode node, int depth) {
        if (node == null) {
            return;
        }
        if (rightSizeList.size() <= depth) {
            rightSizeList.add(node.val);
        }
        dfs(node.right, depth + 1);
        dfs(node.left, depth + 1);
    }

    public List<Integer> rightSideView(TreeNode root) {
        dfs(root, 0);
        return rightSizeList;
    }
}
