// Last updated: 1/18/2026, 4:32:59 PM
1class Solution {
2public:
3    int minOperations(vector<int>& nums, vector<int>& target) {
4        int n = nums.size() ; 
5        int count = 0 ; 
6        set<int>st ; 
7
8        for(int i = 0 ; i<n ; i++)
9        {
10            if(nums[i]!=target[i] && st.find(nums[i])==st.end())
11            {
12                count++ ;
13                st.insert(nums[i]) ; 
14            }
15        }
16       return count ;      
17        
18    }
19};