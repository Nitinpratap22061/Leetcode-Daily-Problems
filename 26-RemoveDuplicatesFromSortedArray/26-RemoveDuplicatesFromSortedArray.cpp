// Last updated: 10/5/2025, 9:02:38 AM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
       set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int i=0;
        for(auto element:s){
            nums[i]=element;
            i++;
        }
        return s.size();      
    }
};