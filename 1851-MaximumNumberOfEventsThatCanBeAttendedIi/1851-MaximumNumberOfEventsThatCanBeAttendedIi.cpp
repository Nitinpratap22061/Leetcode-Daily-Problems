// Last updated: 10/5/2025, 8:54:13 AM
class Solution {
public:
    int solve(vector<vector<int>>& events, int i, int k, vector<vector<int>>& memo) {
        if (i == events.size() || k == 0) return 0;

        if (memo[i][k] != -1) return memo[i][k];

      
        int skip = solve(events, i + 1, k, memo);

      
        int next = i + 1;
        while (next < events.size() && events[next][0] <= events[i][1]) {
            next++;
        }

        int take = events[i][2] + solve(events, next, k - 1, memo);

        return memo[i][k] = max(skip, take);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());

        int n = events.size();
        
     
        vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));

        return solve(events, 0, k, memo);
    }
};
