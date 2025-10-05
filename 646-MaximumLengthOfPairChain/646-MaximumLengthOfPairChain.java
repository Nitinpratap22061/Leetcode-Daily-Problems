// Last updated: 10/5/2025, 8:58:20 AM
import java.util.Arrays;
import java.util.Comparator;

class Solution {
    int[][] t = new int[1001][1001];

    public int solve(int[][] pairs, int i, int p) {
        int n = pairs.length;

        if (i >= n) {
            return 0;
        }
        int offset = p + 1;
        if (t[i][offset] != -1) {
            return t[i][offset];
        }
        int skip = solve(pairs, i + 1, p);
        int take = 0;
        if (p == -1 || pairs[i][0] > pairs[p][1]) {
            take = 1 + solve(pairs, i + 1, i);
        }

        return t[i][offset] = Math.max(take, skip);
    }

    public int findLongestChain(int[][] pairs) {
        int i = 0;
        int p = -1;
        Arrays.sort(pairs, Comparator.comparingInt(a -> a[0]));
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }
        return solve(pairs, i, p);
    }
}

