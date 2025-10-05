// Last updated: 10/5/2025, 8:51:23 AM
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int counting = 0;
        
        for (auto ele : details) {
            int ans = 0;
            for (int i = 0; i < ele.size(); i++) {
                if (i == 11 || i == 12) {
                    ans = ans * 10 + (ele[i] - '0');
                }
            }
            if (ans > 60) {
                counting++;
            }
        }
        
        return counting;
    }
};
