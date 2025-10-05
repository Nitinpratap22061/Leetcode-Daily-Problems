// Last updated: 10/5/2025, 8:57:47 AM
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool checkBipartite(vector<vector<int>>& graph, int start, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0; // Start with color 0 (green) for the initial node
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : graph[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node]; // Flip color
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false; // Invalid coloring, not bipartite
                }
            }
        }
        return true; // All nodes are colored properly, graph is bipartite
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // Initialize all nodes as uncolored (-1)
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                if (!checkBipartite(graph, i, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};
