// Last updated: 10/5/2025, 9:00:26 AM
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;

        for(int i = 0; i < s.size(); i++) {
            char char_s = s[i];
            char char_t = t[i];

            if (s_to_t.find(char_s) != s_to_t.end()) {
                if (s_to_t[char_s] != char_t)
                    return false;
            } else {
                if (t_to_s.find(char_t) != t_to_s.end())
                    return false;

                s_to_t[char_s] = char_t;
                t_to_s[char_t] = char_s;
            }
        }

        return true;
    }
};
