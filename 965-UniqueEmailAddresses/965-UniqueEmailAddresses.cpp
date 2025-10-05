// Last updated: 10/5/2025, 8:57:03 AM
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;

        for (auto &str : emails) {
            string local = "", domain = "";
            bool plus_seen = false;
            int i = 0;

            while (str[i] != '@') {
                if (str[i] == '+') {
                    plus_seen = true; 
                } else if (!plus_seen && str[i] != '.') {
                    local += str[i]; 
                }
                i++;
            }

           
            domain = str.substr(i); 

           
            st.insert(local + domain);
        }

        return st.size();
    }
};
