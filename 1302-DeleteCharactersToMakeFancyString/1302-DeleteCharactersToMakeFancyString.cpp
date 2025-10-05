// Last updated: 10/5/2025, 8:56:02 AM
class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int count = 1;
        
       
        result.push_back(s[0]);
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1; 
            }
            
            
            if (count < 3) {
                result.push_back(s[i]);
            }
        }
        
        return result;
    }
};