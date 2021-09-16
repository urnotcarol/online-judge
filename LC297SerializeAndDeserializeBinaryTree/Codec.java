package LC297SerializeAndDeserializeBinaryTree;

import common.TreeNode;

import java.util.Arrays;
import java.util.LinkedList;

public class Codec {
    private void dfs(TreeNode node, StringBuilder str) {
        str.append(",");
        if (node != null) {
            str.append(node.val);
            dfs(node.left, str);
            dfs(node.right, str);
        }
    }

    public String serialize(TreeNode root) {
        StringBuilder str = new StringBuilder();
        dfs(root, str);
        return str.substring(1);
    }

    private TreeNode dfsRestore(LinkedList<String> queue) {
        if (queue.size() == 0) {
            return null;
        }

        String token = queue.removeFirst();
        if (token.equals("")) {
            return null;
        }
        TreeNode node = new TreeNode(Integer.parseInt(token));
        node.left = dfsRestore(queue);
        node.right = dfsRestore(queue);
        return node;
    }

    public TreeNode deserialize(String data) {
        LinkedList<String> queue = new LinkedList<>(Arrays.asList(data.split(",")));
        return dfsRestore(queue);
    }
}
