// Last updated: 10/5/2025, 8:54:52 AM
class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (auto element : s) {
            if (!st.empty() && abs(int(element) - int(st.top())) == 32) {
                st.pop();
            } else {
                st.push(element);
            }
        }
        
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};
