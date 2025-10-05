// Last updated: 10/5/2025, 8:48:13 AM
class Solution {
public:
    int minOperations(vector<int>& nums) {
  unordered_set<int>st ; 
        for(auto ele : nums)
            {
                st.insert(ele) ; 
            }

            if(st.size()==1)
        {
            return 0 ; 
        }
        return 1 ; 
        
        
    }
};