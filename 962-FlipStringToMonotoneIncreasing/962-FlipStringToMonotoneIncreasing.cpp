// Last updated: 10/5/2025, 8:57:04 AM
class Solution {
public:
    int t[100001][2];
     int n ; 
    int solve(int curr , int prev , string &s)
    {
        if(curr >=n)
        {
            return 0 ; 
        }
        if(t[curr][prev]!=-1)
        {
            return t[curr][prev];
        }
        //options
        int flip = INT_MAX ; 
        int notflip = INT_MAX ;
        if(s[curr]=='0')
        {
            if(prev==0)
            {
            flip = 1+solve(curr+1 , 1 , s);
            notflip = solve(curr+1 , 0 , s);
            }
            else
            {
                flip = 1+solve(curr+1 , 1 , s);
            }
            
        }
        else if(s[curr] == '1')
        {
            if(prev==1)
            {
                notflip = solve(curr+1 , 1,s);
            }
            else
            {
                flip = 1+solve(curr+1 , 0 , s);
                notflip = solve(curr+1 , 1 , s);
            }
        }
        return t[curr][prev] = min(flip , notflip);
    }
    int minFlipsMonoIncr(string s) {
        n = s.size() ;
        memset(t,-1,sizeof(t));
        return solve(0 , 0 , s);
        
    }
};