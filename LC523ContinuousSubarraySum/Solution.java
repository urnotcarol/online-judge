package LC523ContinuousSubarraySum;

import java.util.HashMap;

public class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int maxLength = 0;

        int counter = 0;
        HashMap<Integer, Integer> modIndexMap = new HashMap<>();
        modIndexMap.put(0, -1);

        int numsLen = nums.length;
        for (int i = 0; i < numsLen; i++) {
            counter = (counter + nums[i]) % k;
            if (modIndexMap.containsKey(counter)) {
                maxLength = Math.max(maxLength, i - modIndexMap.get(counter));
            } else {
                modIndexMap.put(counter, i);
            }
        }

        return maxLength > 1;
    }
}
