// Last updated: 10/5/2025, 8:56:28 AM
class Solution {
public:
int t[1001][1002];
   static bool myFunc(string &word1 , string &word2)
   {
    return word1.length()<word2.length();
   }

   bool checkPredecesor(string &prev , string &curr)
   {
    int M = prev.length();
    int N = curr.length();
    if(M>N || N-M !=1)
    {
        return false;
    }
    int i = 0 ; int j = 0 ;
    while(i<M && j<N)
    {
        if(prev[i] == curr[j])
        {
            i++;
        }
        j++;
    }
    return i==M;
   }
   int solve(vector<string>& words,int i , int p)
   {
    if(i>=n)
    {
        return 0;
    }
    int extra = p+1;
    if(t[i][extra]!=-1)
    {
        return t[i][extra];
    }
    //take
    int take = 0;
    int skip = 0;
    if(p==-1 || checkPredecesor(words[p] , words[i]))
    {
         take = 1+solve(words , i+1 , i);
    }
    skip = solve(words,i+1,p);

    return t[i][extra] = max(take,skip);
   
   }
    int n;
    int longestStrChain(vector<string>& words) {
        n = words.size();
        memset(t,-1,sizeof(t));
        sort(begin(words),end(words),myFunc);
        return solve(words,0,-1);

        
    }
};