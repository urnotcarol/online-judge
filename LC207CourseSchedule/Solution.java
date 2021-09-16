package LC207CourseSchedule;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

enum Status { VISITING, VISITED }

class Solution {
    private Status[] statuses;
    private final HashMap<Integer, List<Integer>> graph = new HashMap<>();

    private void buildGraph(int numCourses, int[][] prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            graph.put(i, new ArrayList<>());
        }
        for (int[] prerequisite : prerequisites) {
            graph.get(prerequisite[1]).add(prerequisite[0]);
        }
    }

    private boolean isCyclic(int idx) {
        statuses[idx] = Status.VISITING;

        for (Integer outDegree : graph.get(idx)) {
            if (statuses[outDegree] == Status.VISITING) {
                return true;
            }

            if (statuses[outDegree] != Status.VISITED) {
                if (isCyclic(outDegree)) {
                    return true;
                }
            }
        }

        statuses[idx] = Status.VISITED;
        return false;
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        buildGraph(numCourses, prerequisites);

        statuses = new Status[numCourses];
        for (int idx = 0; idx < numCourses; idx++) {
            if (statuses[idx] != Status.VISITED && isCyclic(idx)) {
                return false;
            }
        }
        return true;
    }
}
