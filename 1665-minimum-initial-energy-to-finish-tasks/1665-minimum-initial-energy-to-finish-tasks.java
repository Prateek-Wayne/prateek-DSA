class Solution {

    public int minimumEffort(int[][] tasks) {

        // sort by (minimum - actual) in descending order
        Arrays.sort(tasks, (a, b) ->
            (b[1] - b[0]) - (a[1] - a[0])
        );

        long ans = 0;
        long energy = 0;

        for (int i = 0; i < tasks.length; i++) {

            int actual = tasks[i][0];
            int minimum = tasks[i][1];

            // increase initial energy if needed
            if (energy < minimum) {
                ans += (minimum - energy);
                energy = minimum;
            }

            // perform task
            energy -= actual;
        }

        return (int) ans;
    }
}