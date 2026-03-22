
class Pair {
    int pos;
    double time;

    Pair(int pos, double time) {
        this.pos = pos;
        this.time = time;
    }
}
class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        int n = position.length;
        Pair[] car = new Pair[n];
        for (int i = 0; i < n; i++) {
            car[i] = new Pair(position[i], (double)(target - position[i]) / speed[i]);
        }
        Arrays.sort(car, (a, b) -> b.pos - a.pos);
        int res = 1;
        double previousTime = car[0].time;
        for (int i = 1; i < n; i++) {
            if (car[i].time > previousTime) {
                res++;
                previousTime = car[i].time;
            }
        }
        return res;
    }
}