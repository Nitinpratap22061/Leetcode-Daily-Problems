// Last updated: 10/5/2025, 8:48:39 AM
class Solution {
public:

    int find(int a, vector<int>& parent) {
        if (a != parent[a])
            parent[a] = find(parent[a], parent);
        return parent[a];
    }

    void union_set(int a, int b, vector<int>& parent, vector<int>& rank) {
        int root_a = find(a, parent);
        int root_b = find(b, parent);
        if (root_a != root_b) {
            if (rank[root_a] < rank[root_b]) {
                parent[root_a] = root_b;
            } else if (rank[root_a] > rank[root_b]) {
                parent[root_b] = root_a;
            } else {
                parent[root_b] = root_a;
                rank[root_a]++;
            }
        }
    }

    bool solve(int n, vector<vector<int>>& edges, int k, int mid) {
        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0); 

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];
            if (t > mid) {
                union_set(u, v, parent, rank);
            }
        }

        unordered_set<int> components;
        for (int i = 0; i < n; ++i) {
            components.insert(find(i, parent));
        }

        return components.size() >= k;
    }

    int minTime(int n, vector<vector<int>>& edges, int k) {
        if (edges.empty()) return (k <= n ? 0 : -1);

        int low = 0, high = 1e9, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (solve(n, edges, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
