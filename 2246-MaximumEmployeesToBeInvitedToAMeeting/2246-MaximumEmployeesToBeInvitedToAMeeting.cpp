// Last updated: 10/5/2025, 8:53:03 AM
class Solution {
public:

    int BFS(int start, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        int maxd = 0;
        
        while (!q.empty()) {
            auto [currnode, dist] = q.front();
            q.pop();
            
            for (auto& ngbr : adj[currnode]) {
                if (!visited[ngbr]) {
                    visited[ngbr] = true;
                    q.push({ngbr, dist + 1});
                    maxd = max(maxd, dist + 1);
                }
            }
        }
        return maxd;
    }

    int maximumInvitations(vector<int>& favorite) {
        unordered_map<int, vector<int>> adj;
        int n = favorite.size();

        for (int i = 0; i < n; i++) {
            int u = i;
            int v = favorite[i];
            // Make graph reverse so that we can traverse back to calculate distances
            adj[v].push_back(u);
        }

        int maxcyclelen = 0;
        int happycouple = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                unordered_map<int, int> mp;
                int curr_node = i;
                int curr_node_count = 0;

                while (!visited[curr_node]) { // While cycle not detected
                    visited[curr_node] = true;
                    mp[curr_node] = curr_node_count;
                    int nextnode = favorite[curr_node];
                    curr_node_count++;

                    if (mp.count(nextnode)) { // Cycle detected
                        int cyclelength = curr_node_count - mp[nextnode];
                        maxcyclelen = max(maxcyclelen, cyclelength);

                        if (cyclelength == 2) {
                            vector<bool> visitedNodes(n, false);
                            visitedNodes[curr_node] = true;
                            visitedNodes[nextnode] = true;
                            happycouple += 2 + BFS(curr_node, adj, visitedNodes) + BFS(nextnode, adj, visitedNodes);
                        }
                        break; // Stop after detecting the cycle
                    }

                    curr_node = nextnode;
                }
            }
        }

        return max(happycouple, maxcyclelen);
    }
};
