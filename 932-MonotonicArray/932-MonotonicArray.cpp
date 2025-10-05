// Last updated: 10/5/2025, 8:57:13 AM
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int flag;
        int count;
           count=0;
            flag=0;
       for(int i=1;i<nums.size();i++){
           if (nums[i]<=nums[i-1]){
               flag++;
           }
           if(nums[i]>=nums[i-1]){
               count++;
           }
          
           
       }
      if(flag==nums.size()-1 || count==nums.size()-1){
          return true;
      }
     
      return false;
        
    }
};