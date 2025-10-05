// Last updated: 10/5/2025, 8:58:01 AM
class Solution {
public:
    int t[1001][1001];
    int solve(string &s1 , string &s2 , int i , int j)
    {
        int m = s1.length() ; 
        int n =s2.length() ;
        if(i>=m && j>=n)
        {
            return  0;
        }
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
         if(i>=m)
         {
            return t[i][j] = s2[j] + solve(s1,s2,i,j+1);
         }
         else if(j>=n)
         {
            return t[i][j] =  s1[i] + solve(s1,s2,i+1,j);
         }
         if(s1[i] == s2[j])
         {
            return t[i][j] =  solve(s1,s2,i+1 , j+1) ;
         }
         int del1 = s1[i] + solve(s1,s2,i+1 , j);
         int del2 = s2[j] + solve(s1,s2,i , j+1);
         return t[i][j] = min(del1,del2);

    }
    int minimumDeleteSum(string s1, string s2) {
        memset(t,-1,sizeof(t));
        return solve(s1,s2,0,0);
        
    }
};