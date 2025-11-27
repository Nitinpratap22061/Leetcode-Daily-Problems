// Last updated: 11/27/2025, 5:21:53 PM
1class Solution {
2public:
3    int maxDistance(vector<vector<int>>& arrays) {
4        
5        int globalMin = arrays[0][0];
6        int globalMax = arrays[0].back();
7        int result = 0;
8
9        for (int i = 1; i < arrays.size(); ++i) {
10 
11            int localMin = arrays[i][0];
12            int localMax = arrays[i].back();
13
14          
15            result = max(result, max(localMax - globalMin, globalMax - localMin));
16
17            globalMin = min(globalMin, localMin);
18            globalMax = max(globalMax, localMax);
19        }
20
21        return result;
22    }
23};
24
25
26
27
28