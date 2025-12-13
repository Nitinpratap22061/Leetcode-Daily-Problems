// Last updated: 12/13/2025, 12:44:29 PM
1class Solution {
2public:
3
4    bool isValid(string s)
5    {
6        if (s.empty()) return false;
7        for(auto &ch : s)
8        {
9            if(!isalnum(ch) && ch!='_')
10            {
11                return false ; 
12            }
13        }
14            return true;
15    }
16    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
17        int n   =  code.size() ; 
18        unordered_map<string,int>st ; 
19        st["electronics"] = 0;
20        st["grocery"] = 1;
21        st["pharmacy"] = 2;
22        st["restaurant"] = 3;
23
24        vector<pair<string,string>>result ; 
25        for(int i = 0 ; i< n ; i++)
26        {
27            if(isValid(code[i]) && st.find(businessLine[i])!=st.end() && isActive[i])
28            {
29
30                    result.push_back({businessLine[i] , code[i]}) ; 
31            }
32        }
33
34        sort(result.begin() , result.end());
35          vector<string> sortedCodes;
36        for (auto& p : result) {
37            sortedCodes.push_back(p.second);
38        }
39
40        return sortedCodes;
41        
42    }
43};