class Solution {
    public int maxDistance(int side, int[][] points, int k) {
        int n = points.length;
        long perimeter = 4L * side;

        long[] pos = new long[n];

        // Convert every boundary point into 1D perimeter position
        for (int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];

            if (y == 0) {
                pos[i] = x; // bottom
            } 
            else if (x == side) {
                pos[i] = side + y; // right
            } 
            else if (y == side) {
                pos[i] = 3L * side - x; // top
            } 
            else {
                pos[i] = 4L * side - y; // left
            }
        }

        Arrays.sort(pos);

        // duplicate for circular handling
        long[] arr = new long[2 * n];
        for (int i = 0; i < n; i++) {
            arr[i] = pos[i];
            arr[i + n] = pos[i] + perimeter;
        }

        long low = 0, high = 2L * side, ans = 0;

        while (low <= high) {
            long mid = (low + high) / 2;

            if (canPick(arr, pos, k, mid, side)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int) ans;
    }

    private boolean canPick(long[] arr, long[] base, int k, long dist, int side) {
        int n = base.length;

        for (int start = 0; start < n; start++) {
            int count = 1;
            long first = arr[start];
            long last = first;
            int idx = start;

            while (count < k) {
                long target = last + dist;

                int next = lowerBound(arr, target, idx + 1, start + n);
                if (next >= start + n) break;

                last = arr[next];
                idx = next;
                count++;
            }

            if (count == k) {
                // Check circular first-last pair also satisfies condition
                long gap = (4L * side) - (last - first);

                if (gap >= dist) {
                    return true;
                }
            }
        }

        return false;
    }

    private int lowerBound(long[] arr, long target, int left, int right) {
        int l = left, r = right;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
}