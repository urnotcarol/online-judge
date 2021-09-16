package LC530MinimumAbsoluteDifferenceInBST;

import common.TreeNode;

import java.util.ArrayList;

class Solution {
    public void traversalInorder(TreeNode root, ArrayList<Integer> visited) {
        if (root == null || !(root.val >= 0)) {
            return;
        }
        traversalInorder(root.left, visited);
        visited.add(root.val);
        traversalInorder(root.right, visited);
    }

    public int getMinimumDifference(TreeNode root) {
        ArrayList<Integer> visited = new ArrayList<>();
        traversalInorder(root, visited);

        int length = visited.size();
        int minDiff = visited.get(length - 1);
        for (int i = 0; i < length - 1; i++) {
            minDiff = Math.min(minDiff, Math.abs(visited.get(i + 1) - visited.get(i)));
        }
        return minDiff;
    }
}
