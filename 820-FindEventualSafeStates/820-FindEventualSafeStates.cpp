// Last updated: 10/5/2025, 8:57:41 AM
class Solution {
public:
    unordered_set<int> ans; 

    bool dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecc) {
        visited[u] = true;
        inRecc[u] = true;

        for (int &v : adj[u]) {
            if (!visited[v]) {
                if (dfs(adj, v, visited, inRecc)) {
                    ans.insert(u);
                    return true;  
                }
            } else if (inRecc[v]) { 
                ans.insert(u);
                return true;
            }
        }

        inRecc[u] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m = graph.size();
        unordered_map<int, vector<int>> adj;

       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<bool> inRecc(m, false);
        vector<bool> visited(m, false);

       
        for (int i = 0; i < m; i++) {
            if (!visited[i]) {
                dfs(adj, i, visited, inRecc);
            }
        }

        vector<int> result;
        for (int i = 0; i < m; i++) {
            if (ans.find(i) == ans.end()) { 
                result.push_back(i);
            }
        }

        return result;
    }
};
