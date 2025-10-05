// Last updated: 10/5/2025, 8:57:14 AM
class Solution {
public:
    bool checkBfs(unordered_map<int, vector<int>>& adj, int u,
                  vector<int>& color) {
        queue<int> q;
        q.push(u);
        color[u] = 1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto& v : adj[curr]) {
                if (color[v] == color[curr]) {
                    return false;
                } else if (color[v] == -1) {
                    q.push(v);
                    color[v] = 1 - color[curr];
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        unordered_map<int, vector<int>> adj;
        for (auto& vec : dislikes) {
            int u = vec[0]-1;
            int v = vec[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if ((checkBfs(adj, i, color) == false))

                    return false;
            }
        }

        return true;
    }
};