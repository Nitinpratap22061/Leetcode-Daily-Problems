// Last updated: 12/20/2025, 8:20:47 PM
1class Solution {
2public:
3    int minOperations(vector<int>& nums) {
4       unordered_map<int,int>freq ; 
5        int dup = 0 ; 
6        for(int x : nums)
7            {
8                freq[x]++ ; 
9                if(freq[x]==2)
10                {
11                    dup++ ; 
12                }
13 }
14
15        int ops = 0 ; 
16        int idx = 0 ; 
17        int n = nums.size() ; 
18        while(idx<n && dup>0)
19            {
20                ops++ ; 
21               //3 ele htao map se 
22                
23                for(int k = 0 ;k<3 && idx<n ; k++ , idx++)
24                    {
25                        int val = nums[idx] ; 
26                        if(freq[val]==2)
27                        {
28                            dup-- ; 
29                            
30                        }
31                        freq[val]-- ; 
32                    }
33                
34            }
35        
36            
37        return ops ; 
38    }
39};