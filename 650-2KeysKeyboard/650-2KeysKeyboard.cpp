// Last updated: 10/5/2025, 8:58:13 AM
class Solution {
public:
int t[1001][1001];


int solve(int currA , int clipA , int n)
   {
    if(n==currA)
    {
        return 0;
    }
    if(currA > n)
    {
        return INT_MAX/2;
    }
    if(t[currA][clipA]!=-1)
    {
        return t[currA][clipA];
    }
    int copypaste = 2+solve(currA*2 , currA , n);
    int paste = 1+ solve(currA+clipA , clipA , n);
    return t[currA][clipA]=min(copypaste,paste);
   }
    int minSteps(int n) {

        if(n==1)
        {
            return 0;
        }
        memset(t,-1,sizeof(t));
        return  1+solve(1,1,n);

    }
};