package LC454FourSumII;

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        int sum = 0;
        int length = nums1.length;
        HashMap<Integer, Integer> firstIndexes = new HashMap<>();
        HashMap<Integer, Integer> secondIndexes = new HashMap<>();

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                int firstSum = nums1[i] + nums2[j];
                if (firstIndexes.containsKey(firstSum)) {
                    firstIndexes.put(firstSum, firstIndexes.get(firstSum) + 1);
                } else {
                    firstIndexes.put(firstSum, 1);
                }

                int secondSum = nums3[i] + nums4[j];
                if (secondIndexes.containsKey(secondSum)) {
                    secondIndexes.put(secondSum, secondIndexes.get(secondSum) + 1);
                } else {
                    secondIndexes.put(secondSum, 1);
                }
            }
        }

        for(Map.Entry<Integer, Integer> entry : firstIndexes.entrySet()){
            if (secondIndexes.containsKey(-entry.getKey())) {
                sum += entry.getValue() * secondIndexes.get(-entry.getKey());
            }
        }
        return sum;
    }
}
