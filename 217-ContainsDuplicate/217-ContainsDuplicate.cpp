// Last updated: 10/5/2025, 9:00:18 AM
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int flag=false;;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){

                flag=true;
                break;

            }

        }
        return flag;
    }
};