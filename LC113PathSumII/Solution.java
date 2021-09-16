package LC113PathSumII;

import common.TreeNode;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Solution {
    private boolean isLeaf(TreeNode node) {
        return node.left == null && node.right == null;
    }

    private void dfs(TreeNode node, Stack<Integer> visited, int targetSum, List<List<Integer>> pathList) {
        if (node == null) {
            return;
        }
        visited.push(node.val);
        if (isLeaf(node) && node.val == targetSum) {
            pathList.add(new ArrayList<>(visited));
        }
        dfs(node.left, visited, targetSum - node.val, pathList);
        dfs(node.right, visited, targetSum - node.val, pathList);
        visited.pop();
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> pathList = new ArrayList<>();
        Stack<Integer> visited = new Stack<>();
        dfs(root, visited, targetSum, pathList);
        return pathList;
    }
}
