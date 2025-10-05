// Last updated: 10/5/2025, 8:56:27 AM
class Solution {
public:
    string smallestSubsequence(string s) {


        int n = s.length() ; 
        string res;

        vector<bool>seen(26,false) ; 
        vector<int>lastidx(26) ; 

        for(int i = 0 ; i<n ; i++)
        {
            char ch = s[i] ; 
            lastidx[ch-'a'] = i ;
        }

        for(int i = 0 ; i<n ; i++)
        {
            char ch = s[i] ; 
            int idx = ch-'a' ; 

            if(seen[idx] ==  true) continue ; 

            while(!res.empty() && res.back()>ch && lastidx[res.back()-'a']>i)
            {
                seen[res.back()-'a'] = false ; 
                res.pop_back() ; 

            }
            res.push_back(ch) ; 
            seen[idx] = true ; 
        }
        return res;
        
        
    }
};

