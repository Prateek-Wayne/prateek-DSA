class Solution {
    int countWaviness(int num) {
        int length = (int) (Math.log10(Math.abs(num)) + 1);
        if (length < 3)
            return 0;
        int[] arr = new int[length];
        int count = 0;
        while (num != 0) {
            arr[count] = num % 10;
            num = num / 10;
            count++;
        }
        int waves = 0;
        for (int i = 1; i < length - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                waves++;
            } else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
                waves++;
        }
        return waves;

    }

    public int totalWaviness(int num1, int num2) {
        int count = 0;
        for (int i = num1; i <= num2; i++) {
            count += countWaviness(i);
        }
        return count;
    }
}