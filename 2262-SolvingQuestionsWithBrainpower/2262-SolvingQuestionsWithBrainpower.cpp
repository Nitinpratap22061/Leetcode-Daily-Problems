// Last updated: 10/5/2025, 8:52:58 AM
class Solution {
public:
   long long t[100001];
    int n;
    long long solve(vector<vector<int>>& questions , int i)
    {
        if(i>=n) return 0 ;
        if(t[i]!=-1)
        {
            return t[i];
        }
        long long solved = questions[i][0] + solve(questions,i+questions[i][1]+1);
        long long notSolve = solve(questions , i+1) ;
        return t[i]=max(solved,notSolve);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        memset(t,-1.0,sizeof(t));
        return solve(questions , 0 );
    }
};