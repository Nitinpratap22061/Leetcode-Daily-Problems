// Last updated: 10/5/2025, 9:00:58 AM
class Solution {
public:
    set<string> st; 
    vector<string> res; 
    int n; 
    
    void solve(int i, string &s, string currstring) {
        if (i >= n) {
            res.push_back(currstring); 
            return; 
        }
        for (int l = 1; l <= n - i; l++) {
            string tempword = s.substr(i, l); 
            if (st.count(tempword)) {
                string holder = currstring; 
                if (!currstring.empty()) currstring += " "; 
                currstring += tempword; 
                solve(i + l, s, currstring); 
                currstring = holder; // backtrack
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.length(); 
        for (string &word : wordDict) {
            st.insert(word); 
        }
        solve(0, s, ""); 
        return res; 
    }
};
