// Last updated: 10/5/2025, 8:52:45 AM
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int>temp = {nums.begin() , nums.end()} ; 
        while(temp.size()>1)
        {
            vector<int>newtemp ; 
        for(int i =0 ; i<temp.size()-1 ; i++)
        {
            int ans = (temp[i]+temp[i+1])%10 ; 
            newtemp.push_back(ans) ; 
        }
        temp = newtemp ; 

        }
        return temp[0] ; 
        
    }
};