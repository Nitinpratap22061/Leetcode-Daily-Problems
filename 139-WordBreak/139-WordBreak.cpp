// Last updated: 10/5/2025, 9:01:00 AM
class Solution {
public:
int t[301];
int n ;
    bool solve(int idx , string &s , unordered_set<string> &st)
    {
        if(idx>=n)
        {
            return true;
        }
        if(t[idx]!=-1)
        {
            return t[idx];
        }
        if(st.find(s)!=st.end())
        {
            return t[idx]=true;
        }
        //todo and check 
        for(int l=1 ; l<=n ; l++)
        {
            string temp = s.substr(idx , l);
            if(st.find(temp)!=st.end() && solve(idx+l,s,st))
            {
                return t[idx]=true;
            }
        }
        return t[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        memset(t,-1,sizeof(t));
        unordered_set<string>st(begin(wordDict) , end(wordDict));
        return solve(0,s,st);
        
    }
};