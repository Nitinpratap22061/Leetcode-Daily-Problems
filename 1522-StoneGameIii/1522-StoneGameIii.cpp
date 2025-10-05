// Last updated: 10/5/2025, 8:55:21 AM
class Solution {
public:
int n ;
int t[50001];
    int solve(vector<int>& stone , int i)
    {
        if(i>=n) return 0 ;
        if(t[i]!=-1)
        {
            return t[i];
        }
        int res = stone[i] - solve(stone,i+1);
        if(i+1<n)
        {
        res = max(res,stone[i]+stone[i+1]-solve(stone,i+2));
        }
        if(i+2<n)
        {
        res = max(res , stone[i]+stone[i+1]+stone[i+2] - solve(stone,i+3));
        }
        return t[i] = res;
    }
    string stoneGameIII(vector<int>& stone) {
        n = stone.size() ; 
        memset(t,-1,sizeof(t));
        int diff = solve(stone , 0 );
        if(diff>0)
        {
            return "Alice";
        }
        else if(diff<0)
        {
            return "Bob";
        }
            return "Tie";
        
        
    }
};