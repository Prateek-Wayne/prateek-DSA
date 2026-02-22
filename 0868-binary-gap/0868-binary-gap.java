class Solution {
    public int binaryGap(int n) {
        int curr = -1;
        int prevBitIndexWithOne = -1;
        int currBitIndex = 0;
        int result = 0;
        while (n != 0) {
            curr = (n & 1);
            if (curr == 1) {
                if (prevBitIndexWithOne != -1) {
                    result = Math.max(result, currBitIndex - prevBitIndexWithOne );
                }
                prevBitIndexWithOne = currBitIndex;
            }
            n = n >> 1;
            currBitIndex++;
        }
        return result;
    }
}