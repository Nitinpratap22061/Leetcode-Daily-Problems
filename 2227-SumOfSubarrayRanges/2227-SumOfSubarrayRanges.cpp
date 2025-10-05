// Last updated: 10/5/2025, 8:53:09 AM
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int i=0;
        int j=0;
        int min = INT_MAX;
        int max = INT_MIN;
        int diffrence=0;
        long long sum=0;
        while(i<nums.size()){
           if(j<nums.size()){
            if(  max<nums[j])
            {
                max=nums[j];
            }
             if(min>nums[j]){
                min=nums[j];
            }
             j++;
             diffrence=max-min;
           sum=sum+diffrence;
            }
            if(j==(nums.size())){
                diffrence=0;
                max=INT_MIN;
                min=INT_MAX;
                i++;
                j=i;
            }
        
             
            
        }
        return sum;
   
   
    }
};