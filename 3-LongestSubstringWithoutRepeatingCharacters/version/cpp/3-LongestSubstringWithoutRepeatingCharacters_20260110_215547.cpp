// Last updated: 1/10/2026, 9:55:47 PM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        int n = s.size() ; 
5        int i = 0 ; 
6        int j = 0 ; 
7        int maxi = 0 ; 
8        unordered_map<char,int>mp ; 
9        while(j<n)
10        {
11    
12            while(!mp.empty() && mp.find(s[j])!=mp.end())
13            {
14                mp[s[i]]-- ;
15                if(mp[s[i]]==0)
16                {
17                    mp.erase(s[i]) ; 
18                }
19                i++ ; 
20            }
21            if(mp.find(s[j])==mp.end())
22            {
23                mp[s[j]]++ ; 
24                maxi = max(maxi,j-i+1);
25                j++ ; 
26            }
27            
28        }
29        return maxi ; 
30        
31    }
32};