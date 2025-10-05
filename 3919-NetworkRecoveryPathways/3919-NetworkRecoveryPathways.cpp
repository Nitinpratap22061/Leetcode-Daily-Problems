// Last updated: 10/5/2025, 8:48:35 AM

class Solution {
public:
    int n;
    typedef pair<long long, int> p;

    unordered_map<int, vector<pair<int, int>>> adj; 

    bool solve(int mid, vector<bool>& online, long long k) {
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<long long> cost(n, LLONG_MAX);
        cost[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long costs = pq.top().first ; 
            long long u = pq.top().second;
            pq.pop();

            if (costs > cost[u]) continue;

            for (auto& v : adj[u]) {
                if (v.second >= mid && online[v.first]) {
                    if (costs + v.second <= k && costs + v.second < cost[v.first]) {
                        cost[v.first] = costs + v.second;
                        pq.push({cost[v.first], v.first});
                    }
                }
            }
        }

        return cost[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        adj.clear(); 

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }

        int low = 0;
        int high = 1e9;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (solve(mid, online, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
