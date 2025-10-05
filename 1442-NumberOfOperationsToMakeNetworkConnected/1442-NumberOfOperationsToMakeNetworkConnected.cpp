// Last updated: 10/5/2025, 8:55:39 AM
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& adjList, int u, vector<bool>& visited) {
        visited[u] = true;
        for (int v : adjList[u]) {
            if (!visited[v]) {
                dfs(adjList, v, visited);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if (edges < n - 1) {
            return -1; 
        }
        
        vector<bool> visited(n, false);
        vector<vector<int>> adjList(n);
        for (const auto& connection : connections) {
            adjList[connection[0]].push_back(connection[1]);
            adjList[connection[1]].push_back(connection[0]);
        }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(adjList, i, visited);
                count++;
               
            }
        }
        
        
        if (edges >= n - 1) {
            return count-1 ; 
        }
        
        return -1; 
    }
};
