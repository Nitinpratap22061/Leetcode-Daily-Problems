// Last updated: 10/5/2025, 8:49:59 AM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flips =0 ;
        int fc = 0 ;
        for(int i =0 ; i<nums.size() ; i++)
        {
            if(i>=3 && nums[i-3]==5)
            {
                fc--;
            }
            if(fc%2==nums[i])
            {
                if(i+3>n) return -1;
                flips++;
                fc++;
                nums[i]=5;
            }
        }
        return flips;
        
    }
};