package LC1143longestCommonSubsequence;

import java.util.HashMap;

public class SolutionDFS {
    private String text1;
    private String text2;
    private HashMap<String, Integer> countMemo;

    public int findLongest(int i, int j) {
        String memoKey = i + "_" + j;
        if (countMemo.containsKey(memoKey)) {
            return countMemo.get(memoKey);
        }

        int count = 0;
        if (i < text1.length() && j < text2.length()) {
            if (text2.charAt(j) == text1.charAt(i)) {
                count = Math.max(count, 1 + findLongest(i + 1, j + 1));
            } else {
                count = Math.max(findLongest(i + 1, j), findLongest(i, j + 1));
            }
        }

        countMemo.put(memoKey, count);
        return count;
    }

    public int longestCommonSubsequence(String text1, String text2) {
        this.text1 = text1;
        this.text2 = text2;
        countMemo = new HashMap<>();
        return findLongest(0, 0);
    }
}
