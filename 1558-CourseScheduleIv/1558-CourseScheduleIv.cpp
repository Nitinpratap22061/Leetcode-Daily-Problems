// Last updated: 10/5/2025, 8:55:14 AM
class Solution {
public:
    bool candfs(unordered_map<int, vector<int>>& adj, int u, int v, vector<bool>& visited) {
        if (u == v) return true; 
        visited[u] = true;
        for (int &g : adj[u]) {
            if (!visited[g]) {
                if (candfs(adj, g, v, visited)) {
                    return true; 
                }
            }
        }
        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        
        
        for (auto &vec : prerequisites) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
        }
        
        int q = queries.size();
        vector<bool> res(q, false);
        
        for (int i = 0; i < q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            vector<bool> visited(numCourses, false);
            res[i] = candfs(adj, u, v, visited); 
        }

        return res;
    }
};
