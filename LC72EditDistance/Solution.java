package LC72EditDistance;

public class Solution {
    public int minDistance(String word1, String word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if (len1 == 0 || len2 == 0) {
            return Math.max(len1, len2);
        }
        int[][] dp = new int[len1 + 1][len2 + 1];

        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (word1.charAt(i) == word2.charAt(j)) {
                    int count = 0;
                    if (i > 0 && j > 0) {
                        count = dp[i][j];
                    } else {
                        count = Math.max(i, j);
                    }
                    dp[i + 1][j + 1] = count;
                } else {
                    int count = 0;
                    if (i > 0 && j > 0) {
                        count = Math.min(Math.min(dp[i][j], dp[i + 1][j]), dp[i][j + 1]);
                    } else if (i > 0) {
                        count = dp[i][j + 1];
                    } else if (j > 0) {
                        count = dp[i + 1][j];
                    }
                    dp[i + 1][j + 1] = count + 1;
                }
            }
        }

        return dp[len1][len2];
    }
}
