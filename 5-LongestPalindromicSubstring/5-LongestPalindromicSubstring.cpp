// Last updated: 10/5/2025, 9:03:01 AM
class Solution {
public:
   bool check(string &s , int i , int j)
   {
    if(i>j)
    {
        return true ;
    }
    if(s[i] == s[j])
    {
        return check(s,i+1 , j-1);
    }
    return false;
   }
    string longestPalindrome(string s) {
        int n = s.length() ;
        int maxlen = 0 ;
        int first ;
        int second ; 
        for(int i = 0 ; i<n ; i++)
        {
            for(int j=i ; j<n ; j++)
            {
                if(check(s,i,j))
                {
                   if(j-i+1 > maxlen)
                   {
                      maxlen = j-i+1 ; 
                      first = i ;
                      second = j;
                   }
                }
            }
        }
        
        return s.substr(first , maxlen);
        
    }
};