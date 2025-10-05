// Last updated: 10/5/2025, 8:59:49 AM
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int flag;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){

                flag=nums[i];
                break;

            }

        }
        return flag;
        
    }
};