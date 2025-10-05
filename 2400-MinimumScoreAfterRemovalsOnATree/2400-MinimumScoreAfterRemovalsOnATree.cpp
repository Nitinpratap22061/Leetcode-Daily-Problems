// Last updated: 10/5/2025, 8:52:29 AM
class Solution {
public:
    int timer = 0;

    // DFS entry/exit times
    void dfs(int node, int par, vector<vector<int>>& graph, vector<int>& nums,
             vector<int>& parent, vector<int>& subtreeXor, vector<int>& inTime, vector<int>& outTime) {
        parent[node] = par;
        inTime[node] = ++timer;
        subtreeXor[node] = nums[node];

        for (int neighbor : graph[node]) {
            if (neighbor == par) continue;
            dfs(neighbor, node, graph, nums, parent, subtreeXor, inTime, outTime);
            subtreeXor[node] ^= subtreeXor[neighbor];  // accumulate XOR
        }

        outTime[node] = ++timer;
    }

    // Returns true if u is inside subtree of v
    bool isDescendant(int u, int v, vector<int>& inTime, vector<int>& outTime) {
        return inTime[v] < inTime[u] && outTime[u] < outTime[v];
    }

    int getScore(int a, int b, int c) {
        return max({a, b, c}) - min({a, b, c});
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> parent(n), subtreeXor(n), inTime(n), outTime(n);
        dfs(0, -1, graph, nums, parent, subtreeXor, inTime, outTime);

        int totalXor = subtreeXor[0];
        int minScore = INT_MAX;

        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                int a = edges[i][0], b = edges[i][1];
                int c = edges[j][0], d = edges[j][1];

                // Identify child node (the one whose parent is the other)
                int child1 = parent[a] == b ? a : b;
                int child2 = parent[c] == d ? c : d;

                if (isDescendant(child1, child2, inTime, outTime)) {
                    // child1 inside child2
                    int x = subtreeXor[child1];
                    int y = subtreeXor[child2] ^ x;
                    int z = totalXor ^ subtreeXor[child2];
                    minScore = min(minScore, getScore(x, y, z));
                }
                else if (isDescendant(child2, child1, inTime, outTime)) {
                    // child2 inside child1
                    int x = subtreeXor[child2];
                    int y = subtreeXor[child1] ^ x;
                    int z = totalXor ^ subtreeXor[child1];
                    minScore = min(minScore, getScore(x, y, z));
                }
                else {
                    // Disjoint subtrees
                    int x = subtreeXor[child1];
                    int y = subtreeXor[child2];
                    int z = totalXor ^ x ^ y;
                    minScore = min(minScore, getScore(x, y, z));
                }
            }
        }

        return minScore;
    }
};
