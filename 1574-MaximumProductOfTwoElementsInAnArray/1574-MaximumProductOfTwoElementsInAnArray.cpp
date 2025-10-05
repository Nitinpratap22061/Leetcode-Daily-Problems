// Last updated: 10/5/2025, 8:55:10 AM
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max=INT_MIN;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(max<nums[i]){
                max=nums[i];
            }

        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==max){
                count++;
            }
        }
        int smax=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(smax<nums[i] && nums[i]!=max){
                smax=nums[i];
            }
        }
        if(count<2){
        return (smax-1)*(max-1);
        }
        else{
            return (max-1) * (max-1);
        }
    }
};