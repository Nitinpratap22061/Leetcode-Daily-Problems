// Last updated: 10/5/2025, 8:51:28 AM
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string p = s;
        char key1 = 0, key2 = 0;

        
        for (char ch : s) {
            if (ch != '9') {
                key1 = ch;
                break;
            }
        }

    
        for (char ch : s) {
            if (ch != '0') {
                key2 = ch;
                break;
            }
        }

        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == key1)
                s[i] = '9';
        }

       
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == key2)
                p[i] = '0';
        }

        int ans1 = stoi(s);
        int ans2 = stoi(p);
        return ans1 - ans2;
    }
};
