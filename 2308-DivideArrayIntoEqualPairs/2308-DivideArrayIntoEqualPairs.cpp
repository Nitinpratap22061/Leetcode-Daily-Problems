// Last updated: 10/5/2025, 8:52:51 AM
class Solution {
public:
    unordered_map<int,int>mp;
    bool divideArray(vector<int>& nums) {
        for(auto &ele : nums)
        {
            mp[ele] ++ ;
        }
        for(auto &element : mp)
        {
            if(element.second %2 !=0)
            {
                return false;
            }
        }
        return true;
        
    }
};