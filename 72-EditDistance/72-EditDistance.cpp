// Last updated: 10/5/2025, 9:02:02 AM
class Solution {
public:
    int t[501][501];
    int solve(string &s1 , string &s2 , int i , int j)
    {
        int m = s1.length() ; 
        int n = s2.length();
        if(i==m)
        {
            return n - j ; 
        }
        else if(j==n)
        {
            return m - i ;
        }
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        if(s1[i] == s2[j])
        {
            return t[i][j] = solve(s1,s2,i+1 , j+1);
        }
        else
        {
            int insert = 1+solve(s1,s2,i,j+1);
            int deleten = 1+solve(s1,s2 , i+1 , j);
            int update =  1+solve(s1,s2 , i+1 , j+1);


            return t[i][j] = min({insert , deleten , update});
        }
        return -1;
    }
    int minDistance(string word1, string word2) {
        memset(t,-1,sizeof(t));
        return solve(word1 , word2 , 0 , 0);
        
    }
};