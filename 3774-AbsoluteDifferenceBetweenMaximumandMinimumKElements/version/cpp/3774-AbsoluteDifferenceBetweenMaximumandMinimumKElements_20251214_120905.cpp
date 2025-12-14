// Last updated: 12/14/2025, 12:09:05 PM
1class Solution {
2public:
3    int absDifference(vector<int>& nums, int k) {
4
5        sort(nums.begin() , nums.end()) ; 
6        int sum1 = 0 ;
7        int sum2 = 0 ; 
8        int n = nums.size();
9
10        for(int i = 0 ; i<k ; i++)
11        {
12            sum1+=nums[i];
13            sum2+=nums[n-1-i];
14        }
15        return abs(sum1-sum2);
16        
17    }
18};