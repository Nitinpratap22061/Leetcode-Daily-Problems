// Last updated: 10/5/2025, 8:48:32 AM
class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(auto &ch : s)
            {
                if(isalpha(ch))
                {
                    res+=ch ; 
                }
                else if(ch=='*')
                {
                    if(!res.empty())
                    {
                    res.pop_back();
                    }
                }
                else if(ch=='#')
                {
                    res+=res ; 
                }
                else
                {
                    reverse(begin(res) , end(res));
                }
            }
        return res ; 
        
    }
};