// Last updated: 10/5/2025, 9:01:12 AM
#include <string>
#include <algorithm> // for std::remove_if
#include <cctype>    // for std::isalnum

class Solution {
public:
    bool isPalindrome(string s) {
        // Remove non-alphanumeric characters and convert to lowercase
        s.erase(remove_if(s.begin(), s.end(), [](char c) {
            return !isalnum(c);
        }), s.end());
        
        // Check if the string is a palindrome
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
