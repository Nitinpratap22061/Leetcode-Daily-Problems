// Last updated: 10/5/2025, 8:58:38 AM
class Solution {
public:
     const int M = 1e9+7;
     int t[100001][2][3];
    int solve(int n , int absentday , int latecons)
    {
        if (absentday >= 2 || latecons >= 3)
    return 0;

        if(n==0)
        {
            return 1 ;
        }
        if(t[n][absentday][latecons]!=-1)
        {
            return t[n][absentday][latecons];
        }
        int absent = solve(n-1 , absentday+1 , 0)%M;
        int late = solve(n-1,absentday,latecons+1)%M;
        int present = solve(n-1 , absentday , 0)%M;

        return t[n][absentday][latecons] =  ((absent+late)%M+present)%M;

    }
    int checkRecord(int n) {
        memset(t,-1,sizeof(t));
        return solve(n , 0 , 0);
        
    }
};