package LC514FreedomTrail;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution2 {
    private int ringLen = 0;
    private int keyLen = 0;
    private HashMap<String, List<Integer>> rotatesMemo = new HashMap<>();
    private HashMap<String, Integer> stepsMemo = new HashMap<>();
    private String globalRing;
    private String globalKey;
    private int steps = Integer.MAX_VALUE;

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

    public void rotateTo(int targetIdx, int pointer, int prevSteps) {
        if (targetIdx == keyLen) {
            steps = Math.min(steps, prevSteps);
            return;
        }

        String memoKey = "p" + pointer + "-k" + targetIdx;
//        if (stepsMemo.containsKey(memoKey)) {
//            stepsMemo.get(memoKey);
//        }
        System.out.println(memoKey + ": " + prevSteps);
        stepsMemo.put(memoKey, prevSteps);

        List<Integer> rotates = findRotates(globalKey.charAt(targetIdx), pointer);
        for (Integer rotate : rotates) {
            rotateTo(targetIdx + 1, toValidIndex(pointer + rotate), Math.abs(rotate) + 1 + prevSteps);
        }
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
        System.out.println("start");
        rotateTo(0, 0, 0);
        return steps;
    }
}