// Last updated: 10/5/2025, 8:56:40 AM
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size() ;
        int flips = 0 ;
        int fc = 0 ;
        //vector<bool>isFlipped(n,false) ; 
        for(int i = 0 ; i<n ; i++)
        {
            if(i>=k && nums[i-k]==5)
            {
                fc--;
            }

            if(fc%2==nums[i])
            {
                if(i+k>n) return -1;
                flips++;
                fc++;
                nums[i] = 5;
            }
        }
        return flips;
        
    }
};