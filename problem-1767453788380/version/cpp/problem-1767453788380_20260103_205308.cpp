// Last updated: 1/3/2026, 8:53:08 PM
1class Solution {
2public:
3    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
4
5        vector<int> helper(n, INT_MAX);
6        helper[0] = 0;
7
8        for (auto &ele : restrictions) {
9            int idx = ele[0];
10            int val = ele[1];
11            helper[idx] = min(helper[idx], val);
12        }
13
14        for (int i = 0; i < n - 1; i++) {
15            int extra =  helper[i] + diff[i] ; 
16            helper[i + 1] = min(helper[i + 1],extra);
17        }
18
19      
20        for (int i = n - 2; i >= 0; i--) {
21            int extra = helper[i + 1] + diff[i] ; 
22            helper[i] = min(helper[i],extra);
23        }
24
25        int ans = *max_element(helper.begin(), helper.end());
26        return ans ; 
27    }
28};
29