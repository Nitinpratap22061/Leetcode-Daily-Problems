// Last updated: 10/5/2025, 8:55:35 AM
class Solution {
public:
    int t[301][11] ; 
    int solve(vector<int>& jobDifficulty , int idx , int n , int d)
    {
        int maxd = INT_MIN;
        if(d==1)
        {
           for(int i = idx ; i<n ; i++)
           {
             maxd = max(maxd , jobDifficulty[i]);
           }
           return maxd ; 


        }
            if(t[idx][d]!=-1)
            {
                return t[idx][d];
            }
        //explore 
        maxd=INT_MIN ;
       int final = INT_MAX ;
        for(int i = idx ; i<=n-d ; i++)
        {
            maxd  = max(maxd , jobDifficulty[i]) ; 

            int result = maxd + solve(jobDifficulty , i+1 , n,d-1);

            final = min(final , result) ;
        }
        return t[idx][d] = final ;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size() ; 
        if(d>n)
        {
            return -1 ;
        }
        memset(t,-1,sizeof(t));
        return solve(jobDifficulty , 0 , n , d);
        
    }
};