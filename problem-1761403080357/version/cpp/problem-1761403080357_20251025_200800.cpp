// Last updated: 10/25/2025, 8:08:00 PM
class Solution {
public:
    string lexSmallest(string s) {

        //can look for every k and return lexo smallest 
        int n = s.size() ; 
        string ans = s ; 
        for(int k=1 ; k<=n ; k++)
            {
                string helper1 = s ; 
                string helper2 = s ; 

                reverse(helper1.begin() , helper1.begin()+k) ; 
                reverse(helper2.end()-k , helper2.end()) ; 

                ans = min({ans , helper1 , helper2}) ; 
            }

        return ans ; 
        
    }
};