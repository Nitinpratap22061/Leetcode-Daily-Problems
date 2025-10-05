// Last updated: 10/5/2025, 8:52:05 AM
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> setIndex(31, -1);
        vector<int> result(n);

        for (int i = n-1; i >= 0; i--) {
            int j = i;
            for (int bit = 0; bit < 31; bit++) {
                if (!(nums[i] & (1 << bit))) { //bith set is not set
                    if (setIndex[bit] != -1) { //check which index can set this bit to 1
                        j = max(j, setIndex[bit]);
                    }
                } else {
                    setIndex[bit] = i; //this bit alreasy set at index i
                }
            }

            result[i] = j - i + 1;
        }

        return result;
    }
};