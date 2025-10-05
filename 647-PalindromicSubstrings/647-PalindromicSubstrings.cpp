// Last updated: 10/5/2025, 8:58:14 AM
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length() ;
        int count = 0 ;
        vector<vector<bool>>t(n , vector<bool>(n));
        for(int l=1 ; l<=n ; l++)
        {
            for(int i = 0 ; i+l-1<n ; i++)
            {
                int j = i+l-1;
                if(i==j) //1 len
                {
                    t[i][j] = true ;
                }
                else if(i+1 == j) //2len
                {
                    t[i][j] = (s[i]==s[j]);
                }
                else
                {
                    t[i][j] =  ((s[i]==s[j]) && t[i+1][j-1] );
                }

                if(t[i][j] == true)
                {
                    count ++;
                }
            }
        }
        return count;
        
    }
};