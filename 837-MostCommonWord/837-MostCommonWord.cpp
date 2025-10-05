// Last updated: 10/5/2025, 8:57:35 AM
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        //string stream 

         for (char &c : paragraph) {
            if (isalpha(c)) {
                c = tolower(c);
            } else {
                c = ' '; 
            }
        }

        stringstream ss(paragraph) ; 
        string word ; 
        unordered_map<string,int>mp ; 
        set<string>st(banned.begin() , banned.end()) ; 

        while(ss>>word)
        {
            mp[word]++ ; 

        }
        int maxcount = 0 ; 
        string ans = "" ; 
        for(auto &ele:mp)
        {
            if(st.find(ele.first)==st.end())
            {
                if(ele.second>maxcount)
                {
                    maxcount = ele.second ; 
                    ans = ele.first ; 
                }

            }
        }
        return ans ; 
        

        
    }
};