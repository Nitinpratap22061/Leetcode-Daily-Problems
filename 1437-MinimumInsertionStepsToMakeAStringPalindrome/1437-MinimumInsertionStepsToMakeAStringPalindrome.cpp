// Last updated: 10/5/2025, 8:55:41 AM
class Solution {
public:
    int t[501][501];
    int solve(string &s , int i , int j)
    {

        if(i>=j)
        {
            return 0 ; 
        }
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        if(s[i] == s[j])
        {
           return solve(s,i+1 , j-1);
        }
        else
        {
         int opt1 = 1+solve(s,i+1,j);
         int opt2 = 1+solve(s,i,j-1);
         return t[i][j] =  min(opt1,opt2); 
        }
           
    }
    int minInsertions(string s) {
        int n = s.length() ;
        memset(t,-1,sizeof(t));
        return solve(s ,0 , n-1) ;
        
    }
};