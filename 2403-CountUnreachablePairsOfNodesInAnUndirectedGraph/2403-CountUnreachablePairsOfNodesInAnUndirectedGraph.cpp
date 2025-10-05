// Last updated: 10/5/2025, 8:52:28 AM
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited) {
        visited[u] = true;
        long long counting = 1; // Counting nodes in this connected component
        for (int &v : adj[u]) {
            if (!visited[v]) {
                counting += dfs(adj, v, visited);
            }
        }
        return counting;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(n, false);

        for (auto &vec : edges) {
            int a = vec[0];
            int b = vec[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        long long totalPairs = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                long long componentSize = dfs(adj, i, visited);
                totalPairs += componentSize * (n - componentSize); // Number of unreachable pairs from this component
            }
        }

        return totalPairs / 2; // Each pair is counted twice, so divide by 2
    }
};


