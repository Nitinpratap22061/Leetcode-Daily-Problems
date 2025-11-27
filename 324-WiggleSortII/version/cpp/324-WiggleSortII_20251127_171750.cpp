// Last updated: 11/27/2025, 5:17:50 PM
1class Solution {
2public:
3    void wiggleSort(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> sorted = nums;
6        sort(sorted.begin(), sorted.end());
7        
8        
9        int mid = (n - 1) / 2;
10        int end = n - 1;
11
12        
13        int idx = 0;
14
15
16        while (idx < n) {
17            nums[idx] = sorted[mid];
18            mid--;
19            idx += 2;
20        }
21
22        
23        idx = 1;
24
25        
26        while (idx < n) {
27            nums[idx] = sorted[end];
28            end--;
29            idx += 2;
30        }
31    }
32};