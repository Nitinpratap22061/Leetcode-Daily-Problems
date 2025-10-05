// Last updated: 10/5/2025, 8:51:21 AM
class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, int& nodeCount, int& edgeCount) {
        visited[u] = true;
        nodeCount++;
        
        for (auto &v : adj[u]) {
            edgeCount++; 
            if (!visited[v]) {
                dfs(adj, v, visited, nodeCount, edgeCount);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        
        // Build adjacency list
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int nodeCount = 0, edgeCount = 0;
                dfs(adj, i, visited, nodeCount, edgeCount);
                
                
                if ((edgeCount / 2) == (nodeCount * (nodeCount - 1)) / 2) {
                    count++;
                }
            }
        }

        return count;
    }
};
