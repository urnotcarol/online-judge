package LC684RedundantConnection;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Stack;

class SolutionDFS {
    private final HashMap<Integer, ArrayList<Integer>> graph = new HashMap<>();
    private final HashMap<String, Integer> edgeIndex = new HashMap<>();
    private final Stack<Integer> visitedNodes = new Stack<>();
    private Integer meetingIndex = -1;
    private boolean[] visited;

    private String edgeToString(int node1, int node2) {
        return node1 + "-" + node2;
    }

    private void buildGraph(int[][] edges) {
        int length = edges.length;
        for (int i = 0; i < length; i++) {
            int[] edge = edges[i];
            ArrayList<Integer> linkedNodes = graph.get(edge[0]) != null ? graph.get(edge[0]) : new ArrayList<>();
            linkedNodes.add(edge[1]);
            graph.put(edge[0], linkedNodes);

            linkedNodes = graph.get(edge[1]) != null ? graph.get(edge[1]) : new ArrayList<>();
            linkedNodes.add(edge[0]);
            graph.put(edge[1], linkedNodes);

            edgeIndex.put(edgeToString(edge[0], edge[1]), i);
            edgeIndex.put(edgeToString(edge[1], edge[0]), i);
        }
    }

    private boolean findCircle(int node, int prevNode) {
        if (visited[node]) {
            meetingIndex = visitedNodes.indexOf(node);
            return true;
        }

        visited[node] = true;
        visitedNodes.add(node);

        ArrayList<Integer> linkedNodes = graph.get(node);
        for (Integer linkedNode : linkedNodes) {
            if (linkedNode != prevNode && findCircle(linkedNode, node)) {
                return true;
            }
        }

        visitedNodes.pop();
        return false;
    }

    public int[] findRedundantConnection(int[][] edges) {
        buildGraph(edges);
        int total = edges.length + 1;
        visited = new boolean[total];

        findCircle(1, 0);

        int maxIndex = -1;
        List<Integer> circle = visitedNodes.subList(meetingIndex, visitedNodes.size());
        int circleLen = circle.size();
        for (int i = 0; i < circleLen; i++) {
            String edge = edgeToString(circle.get(i), circle.get((i + 1) % circleLen));
            maxIndex = Math.max(maxIndex, edgeIndex.get(edge));
        }

        return edges[maxIndex];
    }
}
