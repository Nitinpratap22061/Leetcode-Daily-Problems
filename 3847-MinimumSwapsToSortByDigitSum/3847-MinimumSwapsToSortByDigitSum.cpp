// Last updated: 10/5/2025, 8:48:50 AM
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int solve(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }

    void dfs(int node, unordered_map<int, vector<int>>& graph, vector<bool>& visited, int& cycle_size) {
        visited[node] = true;
        cycle_size++;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited, cycle_size);
            }
        }
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        auto lambda = [](const vector<int>& temp1, const vector<int>& temp2) {
            if (temp1[1] != temp2[1]) {
                return temp1[1] < temp2[1];
            }
            return temp1[0] < temp2[0];
        };

        vector<vector<int>> ans1;
        for (int i = 0; i < n; i++) {
            int ans = solve(nums[i]);
            ans1.push_back({nums[i], ans, i});
        }

        sort(ans1.begin(), ans1.end(), lambda);

        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++) {
            int original_idx = ans1[i][2];
            graph[original_idx].push_back(i);
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int cycle_size = 0;
                dfs(i, graph, visited, cycle_size);
                if (cycle_size > 1)
                    swaps += (cycle_size - 1);
            }
        }

        return swaps;
    }
};
