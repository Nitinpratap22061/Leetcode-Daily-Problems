// Last updated: 10/5/2025, 8:52:02 AM
class Solution {
public:
    string robotWithString(string s) {
        int n = s.length(); 
        vector<char> minchartoright(n);
        minchartoright[n - 1] = s[n - 1];
        
        for (int i = n - 2; i >= 0; i--) {
            minchartoright[i] = min(s[i], minchartoright[i + 1]);
        }

        stack<char> st; 
        string paper = "";
        
        for (int i = 0; i < n; i++) {
            st.push(s[i]);
            while (!st.empty() && (i == n - 1 || st.top() <= minchartoright[i + 1])) {
                paper += st.top();
                st.pop();
            }
        }
        
        return paper;
    }
};
