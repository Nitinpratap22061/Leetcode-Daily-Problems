// Last updated: 10/5/2025, 8:51:12 AM
class Solution {
public:
    string finalString(string s) {
        string result;
        for (char c : s) {
            if (c == 'i') {
                reverse(result.begin(), result.end());
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};
