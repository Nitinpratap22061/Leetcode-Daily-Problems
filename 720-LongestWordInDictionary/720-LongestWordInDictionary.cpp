// Last updated: 10/5/2025, 8:57:58 AM
#include <vector>
#include <string>
#include <set>
#include <algorithm>

class Solution {
public:
    std::string longestWord(std::vector<std::string>& words) {
        std::set<std::string> s;
        std::string flag;

       
        std::sort(words.begin(), words.end());

        
        s.insert("");

        for (const auto& element : words) {
            if (s.count(element.substr(0, element.size() - 1))) {
                // Insert the current word into the set
                s.insert(element);
                
                // Update the flag if the current word is longer
                if (element.size() > flag.size()) {
                    flag = element;
                }
            }
        }

        return flag;
    }
};
