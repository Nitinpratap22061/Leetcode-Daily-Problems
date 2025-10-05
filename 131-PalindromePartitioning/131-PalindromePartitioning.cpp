// Last updated: 10/5/2025, 9:01:07 AM
class Solution {
public:


       vector<vector<string>>res ; 

       void solve(string &s , vector<string>temp , int i , vector<vector<int>>& dp )
       {
        if(i==s.length())
        {
            res.push_back(temp) ; 
        }

        for(int j = i ; j<s.length() ; j++)
        {
            if(dp[i][j]==1)
            {
                temp.push_back(s.substr(i,j-i+1));
                //explore 
                solve(s,temp,j+1,dp) ; 

                temp.pop_back() ; 
            }
        }
       }
    vector<vector<string>> partition(string s) {


        int n = s.size() ; 


        vector<vector<int>> dp(n, vector<int>(n, 0));  
 // t[i][j] --  i se j palindrome or not 
    

        for(int L=1 ; L<=n ; L++)
        {
            for(int i = 0 ; i+L-1<n ; i++)
            {
                int j = i+L-1; 

                if(i==j)
                {
                    dp[i][j] = 1 ; 
                }
                else if (i+1==j)
                {
                    dp[i][j] = (s[i]==s[j]) ; 
                }
                else
                {
                    dp[i][j] = (s[i]==s[j]) && (dp[i+1][j-1]) ; 
                }
            }
        }

        vector<string>temp ; 
         solve(s,temp , 0  , dp) ; 

         return res;
        
    }
};