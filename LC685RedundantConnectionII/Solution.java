package LC685RedundantConnectionII;

import java.util.*;

enum Status {
    VISITED,
    VISITING,
}

class Solution {
    private final HashMap<Integer, ArrayList<Integer>> graph = new HashMap<>();
    private final HashMap<Integer, ArrayList<Integer>> graphPrevNodes = new HashMap<>();
    private final HashMap<String, Integer> edgeIndex = new HashMap<>();
    private final Stack<Integer> visitedNodes = new Stack<>();
    private int meetingIndex = -1;
    private int twoInDegreeNode = -1;
    private Status[] statues;

    private String edgeStr(int node1, int node2) {
        return node1 + "-" + node2;
    }

    private void buildGraph(int[][] edges) {
        int length = edges.length;
        for (int i = 0; i < length; i++) {
            int[] edge = edges[i];
            ArrayList<Integer> outDegrees = graph.get(edge[0]) != null ? graph.get(edge[0]) : new ArrayList<>();
            outDegrees.add(edge[1]);
            graph.put(edge[0], outDegrees);

            ArrayList<Integer> prevNodes = graphPrevNodes.get(edge[1]) != null ? graphPrevNodes.get(edge[1]) : new ArrayList<>();
            prevNodes.add(edge[0]);
            graphPrevNodes.put(edge[1], prevNodes);
            if (prevNodes.size() > 1) {
                twoInDegreeNode = edge[1];
            }

            edgeIndex.put(edgeStr(edge[0], edge[1]), i);
        }
    }

    private boolean findCircle(int node) {
        if (statues[node] == Status.VISITED) {
            return false;
        }

        if (statues[node] == Status.VISITING) {
            meetingIndex = visitedNodes.indexOf(node);
            return true;
        }

        statues[node] = Status.VISITING;
        visitedNodes.add(node);

        ArrayList<Integer> nextNodes = graph.get(node);
        if (nextNodes != null) {
            for (Integer nextNode : nextNodes) {
                if (findCircle(nextNode)) {
                    return true;
                }
            }
        }

        statues[node] = Status.VISITED;
        visitedNodes.pop();
        return false;
    }

    public int[] findRedundantDirectedConnection(int[][] edges) {
        buildGraph(edges);
        int[] res = new int[]{};

        int nodeCount = edges.length;
        statues = new Status[nodeCount + 1];
        for (int i = 1; i <= nodeCount; i++) {
            if (findCircle(i)) {
                break;
            }
        }

        boolean has2InDegreeNode = twoInDegreeNode != -1;
        boolean hasCircle = meetingIndex != -1;

        List<Integer> prevNodes = has2InDegreeNode ? graphPrevNodes.get(twoInDegreeNode) : null;
        List<Integer> circle = hasCircle ? visitedNodes.subList(meetingIndex, visitedNodes.size()) : null;

        if (has2InDegreeNode && hasCircle) {
            int targetPrevNode = -1;
            for (Integer prevNode : prevNodes) {
                if (circle.contains(prevNode)) {
                    targetPrevNode = prevNode;
                }
            }
            res = new int[]{targetPrevNode, twoInDegreeNode};
        } else if (hasCircle) {
            int maxIndex = -1;
            int circleLen = circle.size();
            for (int i = 0; i < circleLen; i++) {
                maxIndex = Math.max(maxIndex, edgeIndex.get(edgeStr(circle.get(i), circle.get((i + 1) % circleLen))));
            }
            res = edges[maxIndex];
        } else if (has2InDegreeNode) {
            int maxIndex = -1;
            for (Integer prevNode : prevNodes) {
                maxIndex = Math.max(maxIndex, edgeIndex.get(edgeStr(prevNode, twoInDegreeNode)));
            }
            res = edges[maxIndex];
        }

        return res;
    }
}

