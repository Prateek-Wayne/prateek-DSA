
public class Robot {
    int x;
    int y;
    int width;
    int height;
    int[][] dir;
    int d;

    public Robot(int width, int height) {
        this.x = 0;
        this.y = 0;
        this.d = 0;
        this.width = width;
        this.height = height;
        dir = new int[][] { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
    }

    boolean isSafe(int x, int y, int width, int height) {
        return x >= 0 && x < width && y >= 0 && y < height;
    }

    public void step(int num) {
        int cycle = 2 * (width + height - 2);
        num = num % cycle;
        if (num == 0)
            num = cycle;
        for (int i = 0; i < num; i++) {
            int newX = x + dir[d][0];
            int newY = y + dir[d][1];
            if (isSafe(newX, newY, width, height)) {
                x = newX;
                y = newY;
            } else {
                while (!isSafe(newX, newY, width, height)) {
                    d = (d + 1) % 4;
                    newX = x + dir[d][0];
                    newY = y + dir[d][1];
                }
                x = newX;
                y = newY;
            }
        }

    }

    public int[] getPos() {
        return new int[] { x, y };

    }

    public String getDir() {
        switch (d) {
            case 0:
                return "East";
            case 1:
                return "North";
            case 2:
                return "West";
            case 3:
                return "South";
            default:
                return "NONE";
        }
    }
}
