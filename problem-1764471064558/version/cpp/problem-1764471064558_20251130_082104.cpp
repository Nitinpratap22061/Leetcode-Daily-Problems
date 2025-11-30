// Last updated: 11/30/2025, 8:21:04 AM
1class Solution {
2public:
3    int countElements(vector<int>& nums, int k) {
4        sort(begin(nums) , end(nums)) ; 
5        int cand = 0 ; 
6        int n = nums.size() ; 
7        for(int i = 0 ; i<n ; i++)
8            {
9                 int last = upper_bound(nums.begin() , nums.end() , nums[i])-nums.begin()-1 ; 
10                  int ele = n - last -1 ; 
11                if(ele>=k)
12                {
13                    cand++ ; 
14                }
15                
16            }
17        return cand; 
18    }
19};