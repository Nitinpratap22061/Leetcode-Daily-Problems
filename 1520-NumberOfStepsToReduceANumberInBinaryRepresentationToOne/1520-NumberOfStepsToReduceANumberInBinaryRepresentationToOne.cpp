// Last updated: 10/5/2025, 8:55:23 AM
#include <string>

class Solution {
public:
    int numSteps(std::string s) {
        int steps = 0;
        
        // Process the string until it becomes "1"
        while (s != "1") {
            // If the last character is '0', the number is even
            if (s.back() == '0') {
                s.pop_back(); // Remove the last character (divide by 2)
            } else {
                // The number is odd, we need to add 1
                int i = s.size() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i >= 0) {
                    s[i] = '1';
                } else {
                    s = "1" + s;
                }
            }
            steps++;
        }
        
        return steps;
    }
};
