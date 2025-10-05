// Last updated: 10/5/2025, 9:03:03 AM
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        
        for (int end = 0, start = 0; end < n; end++) {
            if (charIndexMap.find(s[end]) != charIndexMap.end()) {
      
                start = max(start, charIndexMap[s[end]] + 1);
            }
           
            maxLength = max(maxLength, end - start + 1);
           
            charIndexMap[s[end]] = end;
        }
        
        return maxLength;
    }
};
