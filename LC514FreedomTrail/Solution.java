package LC514FreedomTrail;

import java.util.*;

class Solution {
    private int ringLen = 0;
    private int keyLen = 0;
    private HashMap<String, List<Integer>> rotatesMemo = new HashMap<>();
    private HashMap<String, Integer> stepsMemo = new HashMap<>();
    private String globalRing;
    private String globalKey;

    private int toValidIndex(int idx) {
        if (idx >= ringLen) {
            return idx % ringLen;
        }
        if (idx < 0) {
            return ringLen - (-idx % ringLen);
        }
        return idx;
    }

    private int toNearerRotate(int idx) {
        if (Math.abs(idx - ringLen) < idx) {
            return idx - ringLen;
        }
        return idx;
    }

    public int rotateTo(int targetIdx, int pointer) {
        if (targetIdx == keyLen) {
            return 0;
        }

        String memoKey = pointer + "-" + targetIdx;
        if (stepsMemo.containsKey(memoKey)) {
            return stepsMemo.get(memoKey);
        }

        int localSteps = Integer.MAX_VALUE;
        List<Integer> rotates = findRotates(globalKey.charAt(targetIdx), pointer);
        for (Integer rotate : rotates) {
            localSteps = Math.min(localSteps, Math.abs(rotate) + 1 + rotateTo(targetIdx + 1, toValidIndex(pointer + rotate)));
        }
        stepsMemo.put(memoKey, localSteps);
        return localSteps;
    }

    private List<Integer> findRotates(char targetChar, int pointer) {
        String memoKey = pointer + "" + targetChar;
        if (rotatesMemo.containsKey(memoKey)) {
            return rotatesMemo.get(memoKey);
        }
        List<Integer> rotates = new ArrayList<>();
        for (int i = 0; i < ringLen; i++) {
            if (globalRing.charAt(toValidIndex(pointer + i)) == targetChar) {
                rotates.add(toNearerRotate(i));
            }
        }
        rotatesMemo.put(memoKey, rotates);
        return rotates;
    }

    public int findRotateSteps(String ring, String key) {
        ringLen = ring.length();
        keyLen = key.length();
        globalRing = ring;
        globalKey = key;

        return rotateTo(0, 0);
    }
}