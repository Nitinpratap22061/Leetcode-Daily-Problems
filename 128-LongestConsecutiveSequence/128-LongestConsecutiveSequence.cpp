// Last updated: 10/5/2025, 9:01:09 AM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size() ; 

        if(nums.size()==0)
        {
            return 0 ; 
        }

        if(nums.size()==1)
        {
            return 1 ; 
        }



       
        sort(begin(nums),end(nums));
         int count =1 ; 
         int maxcount = 1; 

        for(int i= 0 ; i<n-1 ; i++)
        {
            if(nums[i+1]-nums[i]==0) continue ;
             
            if(nums[i+1]-nums[i]==1)
            {
                count++;
            }
             
            else
            {

                count = 1;  
            }
             maxcount  = max(maxcount , count) ; 
           
        }

        return maxcount ; 

    


        
    }
};