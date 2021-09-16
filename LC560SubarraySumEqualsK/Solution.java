package LC560SubarraySumEqualsK;

import java.util.HashMap;

class Solution {
    public int subarraySum(int[] nums, int k) {
        int sum = 0;
        int counter = 0;
        HashMap<Integer, Integer> preIndexes = new HashMap<>();
        preIndexes.put(0, 1);

        int length = nums.length;
        for (int i = 0; i < length; i++) {
            counter += nums[i];
            if (preIndexes.containsKey(counter - k)) {
                sum += preIndexes.get(counter - k);
            }

            if (preIndexes.containsKey(counter)) {
                preIndexes.put(counter, preIndexes.get(counter) + 1);
            } else {
                preIndexes.put(counter, 1);
            }
        }
        return sum;
    }
}