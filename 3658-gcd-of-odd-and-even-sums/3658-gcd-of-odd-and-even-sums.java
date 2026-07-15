class Solution {
    int sumOfProgression(int start,int n){
        int d=2;
        return (n*(2*start+((n-1)*d))/2);
    }

    int gcd(int first, int second) {
        if (first == 0 && second != 0)
            return second;
        if (first != 0 && second == 0)
            return first;
        int i = Math.min(first, second);
        for (; i >= 1; i--) {
            if (first % i == 0 && second % i == 0)
                return i;
        }

        return 1;
    }

    public int gcdOfOddEvenSums(int n) {
        int oddSum = sumOfProgression(1, n);
        int evenSum = sumOfProgression(2, n);
        // System.out.println(oddSum+"|"+evenSum);
        return gcd(oddSum, evenSum);

    }
}