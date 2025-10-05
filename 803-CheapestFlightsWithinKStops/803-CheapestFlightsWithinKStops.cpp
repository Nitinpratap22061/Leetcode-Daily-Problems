// Last updated: 10/5/2025, 8:57:46 AM
class Solution {
public:
    typedef pair<int, int> P;
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto &vec : flights) {
            int u = vec[0], v = vec[1], cost = vec[2];
            mp[u].push_back({v, cost});
        }

        vector<vector<int>> result(n, vector<int>(k + 2, INT_MAX)); 
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({0, src, 0}); 
        result[src][0] = 0;
        
        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            int wt = curr[0], node = curr[1], stops = curr[2];

            if (node == dst) return wt;
            
            if (stops > k) continue; 

            for (auto &[nextnode, price] : mp[node]) {
                int new_cost = wt + price;
                
                if (new_cost < result[nextnode][stops + 1]) {
                    result[nextnode][stops + 1] = new_cost;
                    pq.push({new_cost, nextnode, stops + 1});
                }
            }
        }
        return -1;
    }
};
