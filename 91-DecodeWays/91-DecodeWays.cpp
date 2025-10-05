// Last updated: 10/5/2025, 9:01:41 AM
class Solution {
public:
     int t[101];
    int solve(string &s , int i , int n)
    {
        if(i==n)
        {
            return 1;
        }
        if(s[i]=='0')
        {
            return 0 ; 
        }
        if(t[i]!=-1)
        {
            return t[i];
        }
        int one = solve(s,i+1 , n);
        int two = 0;
        if(i+1<n)
        {
        if(s[i]=='1' || s[i]=='2' && s[i+1]<='6' )
        {
               two = solve(s,i+2,n);
        }
        }
        return t[i]=one + two;
    }
    int numDecodings(string s) {
        int n = s.length() ; 
        memset(t,-1,sizeof(t));
        return solve(s , 0 , n);
        
    }
};