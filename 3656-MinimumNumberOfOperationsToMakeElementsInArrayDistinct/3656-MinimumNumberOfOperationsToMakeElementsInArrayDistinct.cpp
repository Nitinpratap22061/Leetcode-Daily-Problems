// Last updated: 10/5/2025, 8:49:25 AM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int>st(nums.begin() , nums.end());
        unordered_set<int>st1;
        int operation = 0 ;
        
        if(nums.size() == st.size() )
        {
            return 0 ; 
        }
        while(!nums.empty())
        {
            int remove = min(3,(int)nums.size());
            nums.erase(nums.begin() , nums.begin() + remove );
            operation++;
              unordered_set<int>st1(begin(nums) , end(nums));
              if(st1.size() == nums.size())
              {
                return operation;
              }

        }
        return operation;

    }
};