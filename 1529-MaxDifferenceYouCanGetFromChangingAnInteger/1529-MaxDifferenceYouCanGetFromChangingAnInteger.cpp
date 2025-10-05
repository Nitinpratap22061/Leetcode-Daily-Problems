// Last updated: 10/5/2025, 8:55:20 AM
class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);  // for max
        string p = s;               // for min
        char key1 = 0, key2 = 0;

        // Find key1 for max (first digit not equal to '9')
        for (char ch : s) {
            if (ch != '9') {
                key1 = ch;
                break;
            }
        }

        // Replace all key1 with '9' to maximize
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == key1) {
                s[i] = '9';
            }
        }

        // Find key2 for min
        if (p[0] != '1') {
            key2 = p[0]; // safe to replace leading digit with '1'
            for (int i = 0; i < p.size(); ++i) {
                if (p[i] == key2) {
                    p[i] = '1';
                }
            }
        } else {
            // Can't touch leading '1' → find any other digit to replace with '0'
            for (int i = 1; i < p.size(); ++i) {
                if (p[i] != '0' && p[i] != '1') {
                    key2 = p[i];
                    break;
                }
            }
            for (int i = 0; i < p.size(); ++i) {
                if (p[i] == key2) {
                    p[i] = '0';
                }
            }
        }

        int ans1 = stoi(s);  // max value
        int ans2 = stoi(p);  // min value
        return ans1 - ans2;
    }
};
