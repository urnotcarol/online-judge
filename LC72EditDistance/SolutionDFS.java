package LC72EditDistance;

import java.util.HashMap;
import java.util.Objects;

final class Tuple {
    private final int first;
    private final int second;

    Tuple(int first, int second) {
        this.first = first;
        this.second = second;
    }

    public int first() {
        return first;
    }

    public int second() {
        return second;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (obj == null || obj.getClass() != this.getClass()) return false;
        var that = (Tuple) obj;
        return this.first == that.first &&
                this.second == that.second;
    }

    @Override
    public int hashCode() {
        return Objects.hash(first, second);
    }

    @Override
    public String toString() {
        return "<" + first + ", " + second + ">";
    }
}

public class SolutionDFS {
    private String word1;
    private String word2;
    private final HashMap<String, Integer> countMemo = new HashMap<>();

    public int findMinDistance(int i, int j, int prevI, int prevJ) {
        String memoKey = i + "_" + j + "_" + prevI + "_" + prevJ;
        if (countMemo.containsKey(memoKey)) {
            return countMemo.get(memoKey);
        }

        Tuple prevTuple = new Tuple(prevI, prevJ);

        int count;
        if (i == word1.length() || j == word2.length()) {
            Tuple curTuple = new Tuple(word1.length(), word2.length());
            count = countEdited(curTuple, prevTuple);
        } else {
            if (word1.charAt(i) == word2.charAt(j)) {
                Tuple curTuple = new Tuple(i, j);
                count = countEdited(curTuple, prevTuple) + findMinDistance(i + 1, j + 1, i, j);
            } else {
                count = Math.min(findMinDistance(i + 1, j, prevI, prevJ), findMinDistance(i, j + 1, prevI, prevJ));
            }
        }

        countMemo.put(memoKey, count);
        return count;
    }

    public int countEdited(Tuple curTuple, Tuple prevTuple) {
        int iOffset = curTuple.first() - prevTuple.first() - 1;
        int jOffset = curTuple.second() - prevTuple.second() - 1;
        return Math.max(iOffset, jOffset);
    }

    public int minDistance(String word1, String word2) {
        this.word1 = word1;
        this.word2 = word2;

        return findMinDistance(0, 0, -1, -1);
    }
}
