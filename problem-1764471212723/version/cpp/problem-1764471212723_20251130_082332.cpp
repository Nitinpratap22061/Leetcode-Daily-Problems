// Last updated: 11/30/2025, 8:23:32 AM
1class Solution {
2public:
3    int maxDistinct(string s) {
4        set<char>st ; 
5        for(int i = 0 ; i<s.size() ; i++)
6            {
7                char ch = s[i] ; 
8                st.insert(ch) ; 
9            }
10        return st.size() ; 
11        
12    }
13};