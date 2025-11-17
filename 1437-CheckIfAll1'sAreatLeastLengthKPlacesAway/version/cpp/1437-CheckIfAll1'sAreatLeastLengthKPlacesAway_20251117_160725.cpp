// Last updated: 11/17/2025, 4:07:25 PM
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        int flag = -1 ; 
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                flag = i;//first occurence 
                break ; 
            }
        }

        if(flag==-1)
        {
            return true ; 
        }
        int dist = 0;

        for (int i = flag+1; i < n; i++) {
            if (nums[i] != 1) {
                dist++;
            } else {
                if (dist < k) {
                    return false;
                }
                dist = 0;
            }
        }

        return true; 
    }
};