// Last updated: 10/5/2025, 8:48:30 AM
class Solution {
public:

    bool isValid(string s)
    {
        if (s.empty()) return false;
        for(auto &ch : s)
        {
            if(!isalnum(ch) && ch!='_')
            {
                return false ; 
            }
        }
            return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n   =  code.size() ; 
        unordered_map<string,int>st ; 
        st["electronics"] = 0;
        st["grocery"] = 1;
        st["pharmacy"] = 2;
        st["restaurant"] = 3;

        vector<pair<string,string>>result ; 
        for(int i = 0 ; i< n ; i++)
        {
            if(isValid(code[i]) && st.find(businessLine[i])!=st.end() && isActive[i])
            {

                    result.push_back({businessLine[i] , code[i]}) ; 
            }
        }

        sort(result.begin() , result.end());
          vector<string> sortedCodes;
        for (auto& p : result) {
            sortedCodes.push_back(p.second);
        }

        return sortedCodes;
        
    }
};