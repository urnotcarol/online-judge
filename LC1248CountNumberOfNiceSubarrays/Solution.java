package LC1248CountNumberOfNiceSubarrays;

import java.util.HashMap;

class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int sum = 0;
        int counter = 0;
        HashMap<Integer, Integer> preCounts = new HashMap<>();
        preCounts.put(0, 1);

        int length = nums.length;
        for (int i = 0; i < length; i++) {
            counter += nums[i] % 2;
            preCounts.put(counter, preCounts.getOrDefault(counter, 0) + 1);

            if (counter - k > -1 && preCounts.containsKey(counter - k)) {
                sum += preCounts.get(counter - k);
            }
        }
        return sum;
    }
}