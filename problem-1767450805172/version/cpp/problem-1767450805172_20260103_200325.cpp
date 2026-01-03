// Last updated: 1/3/2026, 8:03:25 PM
1class Solution {
2public:
3    string reversePrefix(string s, int k) {
4        int n = s.size() ; 
5        reverse(s.begin() , s.begin()+k) ; 
6        return s ; 
7        
8    }
9};