package LC1143longestCommonSubsequence;

public class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        int[][] dp = new int[len1 + 1][len2 + 1];
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                int count;
                if (text1.charAt(i) == text2.charAt(j)) {
                    count = dp[i][j] + 1;
                } else {
                    count = Math.max(dp[i][j + 1], dp[i + 1][j]);
                }
                dp[i + 1][j + 1] = count;
            }
        }
        return dp[len1][len2];
    }
}
