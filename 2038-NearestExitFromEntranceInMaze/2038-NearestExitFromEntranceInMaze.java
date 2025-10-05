// Last updated: 10/5/2025, 8:53:46 AM
import java.util.*;

class Solution {
    private final int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    public int nearestExit(char[][] maze, int[] entrance) {
        int rows = maze.length;
        int col = maze[0].length;
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int steps = 0;

        while (!q.isEmpty()) {
            int N = q.size();
            while (N-- > 0) {
                int[] temp = q.poll();
                int i = temp[0];
                int j = temp[1];

                if (!(i == entrance[0] && j == entrance[1]) && 
                    (i == 0 || i == rows - 1 || j == 0 || j == col - 1)) {
                    return steps;
                }

                // Explore the directions up, down, left, & right
                for (int[] dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if (new_i >= 0 && new_i < rows && new_j >= 0 && new_j < col && maze[new_i][new_j] != '+') {
                        q.offer(new int[]{new_i, new_j});
                        maze[new_i][new_j] = '+';
                    }
                }
            }
            steps++;
        }
        return -1;
    }
}

