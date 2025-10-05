// Last updated: 10/5/2025, 8:49:52 AM
class Solution {
public:
    int N;
    int sp(unordered_map<int, vector<int>>& adj, int source, int dst) {
        queue<int> q;
        q.push(source);
        vector<bool> visited(N, false);
        visited[source] = true;
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front();
                q.pop();
                if (node == dst) {
                    return level;
                }
                for (auto& v : adj[node]) {
                    if (!visited[v]) {
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        N=n;
        for (int i = 0; i <= n - 2; i++) {
            adj[i].push_back(i + 1);
        }
        vector<int> res;
        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];

            adj[u].push_back(v);
            int ans = sp(adj, 0, n-1);
            
          

            res.push_back(ans);
        }
        return res;
    }
};