// Last updated: 10/5/2025, 8:02:30 AM
class Solution {
public:
    int alternatingSum(vector<int>& nums) {
         int sum = 0 ; 
        int diff = 0 ; 

        for(int i = 0 ; i<nums.size() ; i++)
            {
                if(i%2==0)
                {
                    sum+=nums[i] ; 
                }
                else
                {
                    diff-=nums[i] ; 
                }
                
            }

        return sum+diff ; 
        
    }
};