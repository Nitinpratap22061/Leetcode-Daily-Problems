// Last updated: 11/29/2025, 11:30:20 PM
1class Solution {
2public:
3
4    int count;
5    bool ok; // NEW: to track invalid cases
6
7    int dfs(int curr, int parent, int target, unordered_map<int,vector<int>>& mp, vector<int>& nums) {
8
9        if (!ok) return 0; // NEW: early exit
10
11        int sum = nums[curr];
12        for (int &ngbr : mp[curr]) {
13            if (ngbr != parent) {
14                sum += dfs(ngbr, curr, target, mp, nums);
15            }
16        }
17
18        if (sum == target) {
19            count++;
20            return 0;      // NEW: cut component
21        }
22
23        if (sum > target) ok = false; // NEW: invalid partition
24
25        return sum;
26    }
27
28    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
29
30        if (edges.size() == 0) return 0;
31
32        unordered_map<int,vector<int>> mp;
33        for (auto &edge : edges) {
34            mp[edge[0]].push_back(edge[1]);
35            mp[edge[1]].push_back(edge[0]);
36        }
37
38        int sum = accumulate(nums.begin(), nums.end(), 0);
39        int ans = 0;
40
41        // NEW: Try only divisors of total sum
42        for (int x = 1; x * x <= sum; x++) {
43            if (sum % x == 0) {
44
45                // Try divisor x
46                count = 0; ok = true;
47                dfs(0, -1, x, mp, nums);
48                if (ok) ans = max(ans, count - 1);
49
50                int y = sum / x;
51                if (y != x) {
52                    count = 0; ok = true;
53                    dfs(0, -1, y, mp, nums);
54                    if (ok) ans = max(ans, count - 1);
55                }
56            }
57        }
58
59        return ans;
60    }
61};
62