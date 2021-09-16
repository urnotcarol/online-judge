package LC845LongestMountainInArray;

class Solution {
    public int longestMountain(int[] arr) {
        if (arr.length == 1) {
            return 0;
        }

        int maxLen = 0;
        int counterUp = 0;
        int counterDown = 0;
        int length = arr.length;
        for (int i = 1; i < length; i++) {
            if (arr[i] == arr[i - 1]) {
                counterUp = 0;
                counterDown = 0;
                continue;
            }

            if (arr[i] > arr[i - 1]) {
                if (counterDown > 0) {
                    counterUp = 0;
                }
                counterDown = 0;
                counterUp++;
            } else {
                counterDown++;
                if (counterUp > 0) {
                    maxLen = Math.max(maxLen, counterUp + counterDown + 1);
                }
            }
        }

        return maxLen;
    }
}
