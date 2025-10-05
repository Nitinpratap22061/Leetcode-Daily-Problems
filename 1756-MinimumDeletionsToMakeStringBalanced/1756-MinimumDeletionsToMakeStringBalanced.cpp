// Last updated: 10/5/2025, 8:54:34 AM
class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') {
                if (!st.empty() && st.top() == 'b') {
                    st.pop();
                    count++;
                }

                else {
                    st.push(s[i]);
                }
            } else {
                st.push(s[i]);
            }
        }
        return count;
    }
};