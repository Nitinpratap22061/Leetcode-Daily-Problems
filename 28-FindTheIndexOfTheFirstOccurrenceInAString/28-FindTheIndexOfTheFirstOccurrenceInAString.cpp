// Last updated: 10/5/2025, 9:02:36 AM
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        size_t pos = haystack.find(needle);

        if (pos != std::string::npos) {
            return static_cast<int>(pos);
        } else {
            return -1;
        }
    }
};
