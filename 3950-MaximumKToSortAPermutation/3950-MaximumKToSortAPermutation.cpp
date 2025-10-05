// Last updated: 10/5/2025, 8:48:24 AM
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int anda = 0;
        int count =0 ; 

        for (int i = 0; i < nums.size(); i++) {
            if (i != nums[i]) {
                if (anda == 0 && count ==0) {      
                    anda = nums[i]; 
                    count++;   
                } else {
                    anda &= nums[i];  
                }
            }
        }
        return anda; 
    }
};
