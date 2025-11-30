// Last updated: 11/30/2025, 8:49:43 AM
1class Solution {
2public:
3    int solve(int num)
4    {
5        string helper = to_string(num) ; 
6        reverse(begin(helper) , end(helper)) ; 
7        int i = 0 ; 
8        while(helper[i]=='0')
9            {
10                i++ ; 
11            }
12        string ans ="" ; 
13        for(int k = i ; k<helper.size() ; k++)
14            {
15                ans+=helper[k] ; 
16            }
17        int final = stoi(ans) ; 
18        return final ; 
19    }
20        int minMirrorPairDistance(vector<int>& nums) {
21
22        int n = nums.size() ; 
23        unordered_map<int,int>mp ; 
24        for(int i = 0 ; i<n ; i++)
25            {
26                mp[nums[i]] = i ; 
27            }
28        int ans = INT_MAX ; 
29        for(int i = 0 ; i<n ; i++)
30            {
31                int rev= solve(nums[i]) ; 
32                if(mp.find(rev)!=mp.end())
33                {
34                    int idx = mp[rev] ; 
35                    if(idx>i)
36                    {
37                    ans = min(ans , idx-i) ;
38                    }
39                }
40            }
41         if(ans==INT_MAX)
42         {
43             return -1 ;
44         }
45            return ans ; 
46        
47    }
48};