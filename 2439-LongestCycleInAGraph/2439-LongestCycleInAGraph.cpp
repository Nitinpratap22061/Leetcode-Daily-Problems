// Last updated: 10/5/2025, 8:52:17 AM
class Solution {
public:
    int res = -1;
    void dfs(vector<int>& edges, int u, vector<bool>& visited,
            vector<bool>& inrecc, vector<int>& count) {
        visited[u] = true;
        inrecc[u] = true;
        // kahan jaa skte

        int v = edges[u];
        if (v != -1) {
            if (!visited[v]) {
                count[v] = count[u] + 1;
               dfs(edges, v, visited, inrecc, count);
            } else if (inrecc[v] == true) {
                res = max(res, count[u] - count[v] + 1);
            }
        }
        inrecc[u]=false;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<int> count(n, 1);
        vector<bool> inrecc(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(edges, i, visited, inrecc, count);
            }
        }
        return res;
    }
};
