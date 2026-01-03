// Last updated: 1/3/2026, 8:15:06 PM
1class Solution {
2public:
3    int minLength(vector<int>& nums, int k) {
4        int n = nums.size() ; 
5        int  i = 0 ; 
6        int j  = 0 ; 
7        int sum = 0 ; 
8        int ans = INT_MAX ; 
9        unordered_map<int,int>mp ; 
10        while(j<n)
11            {
12                int ele = nums[j] ; 
13                if(mp[ele]==0)
14                {
15                    sum+=ele ; 
16                }
17                mp[ele]++ ; 
18                while(sum>=k)
19                    {
20                        ans = min(ans , j - i +1);
21                       mp[nums[i]]-- ; 
22                        if(mp[nums[i]]==0)
23                        {
24                            sum-=nums[i] ; 
25                        }
26                        i++ ; 
27                    }
28                j++ ; 
29            }
30        if(ans==INT_MAX)
31        {
32            return -1 ; 
33        }
34        return ans ; 
35        
36    }
37};