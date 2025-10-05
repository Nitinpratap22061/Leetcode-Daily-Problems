// Last updated: 10/5/2025, 8:58:06 AM
class Solution {
public:
    bool checkValidString(string s) {
        int balance = 0;
        int wildcard = 0;
        
        for (char c : s) {
            if (c == '(') {
                balance++;
            } else if (c == ')') {
                if (balance == 0 && wildcard == 0) {
                    return false;
                }
                if (balance > 0) {
                    balance--;
                } else {
                    wildcard--;
                }
            } else if (c == '*') {
                wildcard++;
            }
        }
        
        balance = 0;
        wildcard = 0;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if (c == ')') {
                balance++;
            } else if (c == '(') {
                if (balance == 0 && wildcard == 0) {
                    return false;
                }
                if (balance > 0) {
                    balance--;
                } else {
                    wildcard--;
                }
            } else if (c == '*') {
                wildcard++;
            }
        }
        
        return true;
    }
};
