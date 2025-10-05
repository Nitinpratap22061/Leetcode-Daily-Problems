// Last updated: 10/5/2025, 8:48:45 AM
class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Try making all elements 1
        vector<int> temp1 = nums;
        int ops1 = 0;
        for (int i = 0; i < n - 1; i++) {
            if (temp1[i] == -1) {
                temp1[i] *= -1;
                temp1[i + 1] *= -1;
                ops1++;
            }
        }

        bool all1 = true;
        for (int i = 0; i < n; i++) {
            if (temp1[i] != 1) {
                all1 = false;
                break;
            }
        }

        // Try making all elements -1
        vector<int> temp2 = nums;
        int ops2 = 0;
        for (int i = 0; i < n - 1; i++) {
            if (temp2[i] == 1) {
                temp2[i] *= -1;
                temp2[i + 1] *= -1;
                ops2++;
            }
        }

        bool allNeg1 = true;
        for (int i = 0; i < n; i++) {
            if (temp2[i] != -1) {
                allNeg1 = false;
                break;
            }
        }

        return (all1 && ops1 <= k) || (allNeg1 && ops2 <= k);
    }
};
