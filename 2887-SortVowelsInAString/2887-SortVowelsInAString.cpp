// Last updated: 10/5/2025, 8:51:11 AM


class Solution {
public:
    string sortVowels(std::string s) {
        int n = s.size();
        string t(n, ' '); 

        vector<char> helper;

    
        for (auto ch : s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                helper.push_back(ch);
            }
        }

      
        std::sort(helper.begin(), helper.end());

        int count = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                t[i] = helper[count++];
            } else {
                t[i] = ch;
            }
        }

        return t;
    }
};
