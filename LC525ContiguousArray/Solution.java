package LC525ContiguousArray;

import java.util.HashMap;

public class Solution {
    public int findMaxLength(int[] nums) {
        int maxLength = 0;

        HashMap<Integer, Integer> leftIndexes = new HashMap<>();
        leftIndexes.put(0, -1);

        int counter = 0;
        for (int i = 0; i < nums.length; i++) {
            counter = counter + (nums[i] == 1 ? 1 : -1);

            if (leftIndexes.containsKey(counter)) {
                maxLength = Math.max(maxLength, i - leftIndexes.get(counter));
            } else {
                leftIndexes.put(counter, i);
            }
        }

        return maxLength;
    }
}
