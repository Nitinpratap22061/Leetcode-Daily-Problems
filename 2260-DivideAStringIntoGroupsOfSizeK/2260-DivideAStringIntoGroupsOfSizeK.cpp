// Last updated: 10/5/2025, 8:52:59 AM
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans ; 
        string res="";
        for(int i = 0 ; i<s.size() ; i++)
        {
             res+=s[i];
            if(res.length()==k)
            {
                ans.push_back(res);
                res="";
            }
           
            
        }
        if(!res.empty())
        {
            int fillpos = k-res.size();
            for(int i = 0 ; i<fillpos ; i++)
            {
                res+=fill;     
            }
            ans.push_back(res);
        }
        return ans ; 
        
        
    }
};