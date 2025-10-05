// Last updated: 10/5/2025, 8:58:29 AM
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ; 
        unordered_map<int,int>mp ; 
        //s--1 count freq of each number 
         for(int num : nums)
         {
            mp[num]++;
         }
         int maxl = 0 ; 
         for(auto &[num,count]:mp)
         {
            if(mp.count(num+1))
            {
                int length  = count + mp[num+1];
                maxl = max(maxl,length);
            }
         }
         return maxl;

        
    }
};