// Last updated: 10/5/2025, 8:58:08 AM
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> last(10, -1);

        for (int i = 0; i < n; i++) {
            last[s[i] - '0'] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int d = 9; d > s[i] - '0'; d--) {
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return stoi(s);
                }
            }
        }

        return num;
    }
};
