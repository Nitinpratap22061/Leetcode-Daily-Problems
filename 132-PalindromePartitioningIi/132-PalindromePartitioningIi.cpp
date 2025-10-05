// Last updated: 10/5/2025, 9:01:06 AM
class Solution {
public:
int t[2001][2001];
// int p[2001][2001];
//     bool isPalindrome(string &s , int i , int j)
//     {
//         if(i>=j)
//         {
//             return true ;
//         }
//         if(p[i][j]!=-1)
//         {
//             return p[i][j];
//         }
//         if(s[i]==s[j])
//         {
//             return p[i][j] = isPalindrome(s,i+1 , j-1);
//         }
//         return p[i][j] = false;
//     }
    // int solve(string &s , int i , int j , vector<vector<bool>>&dp)
    // {
    //     if(dp[i][j])
    //     {
    //         return 0 ;
    //     }
    //     if(t[i][j]!=-1)
    //     {
    //         return t[i][j];
    //     }
    //     //explore all cuts 
    //     int res = INT_MAX;
    //     for(int k = i ; k<=j-1 ; k++)
    //     {
    //         int temp = 1+solve(s,i,k , dp) + solve(s,k+1,j ,dp) ;
    //         res = min(res,temp);
    //     }
    //     return t[i][j] =  res ; 
    // }
    int minCut(string s) {
        int n = s.length();
       


        //bottom up ---- >  blueprint ; 
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i = 0 ; i <n ; i++)
        {
            dp[i][i] = true ;
        }
        for(int l=2 ; l<=n ; l++)
        {
            for(int i=0 ; i<n-l+1 ; i++)
            {
                int j = i+l-1;
                if(s[i] == s[j])
                {
                    if(l==2)
                    {
                        dp[i][j] = true ;
                    }
                    else
                    {
                        dp[i][j] = dp[i+1][j-1] ;
                     }
                }
            } 
        }


        vector<int>t(n) ; 
        for(int i = 0 ; i < n ; i++)
        {
            if(dp[0][i] == true)
            {
                t[i] = 0 ;
            }
            else
            {
                t[i] = INT_MAX;
                for(int k=0 ; k<i ; k++)
                {
                    if(dp[k+1][i] == true && 1+t[k] < t[i])
                    {
                        t[i] = 1+t[k];
                    }
                }
            }
        }
        return t[n-1];
     
          
        
    }
};