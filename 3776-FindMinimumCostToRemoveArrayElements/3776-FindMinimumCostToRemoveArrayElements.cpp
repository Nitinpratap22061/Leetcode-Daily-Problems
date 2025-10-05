// Last updated: 10/5/2025, 8:49:03 AM
class Solution {
public:
    int t[1001][1001] ; 
    int solve(int i , int j , vector<int>& nums)
    {
         if(j == nums.size()) return nums[i];

         if(j==nums.size()-1)
         {
            return max(nums[j] , nums[i]) ; 
         }

         if(t[i][j]!=-1)
         {
            return t[i][j];
         }


        int op1 = max(nums[i] , nums[j])+solve(j+1 , j+2 , nums) ; 
        int op2 =  max(nums[i] , nums[j+1]) + solve(j , j+2 , nums) ;
        int op3 = max(nums[j] , nums[j+1]) + solve(i , j+2 , nums) ; 

        return t[i][j] = min({op1,op2,op3}) ; 
    }
    int minCost(vector<int>& nums) {

           memset(t,-1,sizeof(t));
        return solve(0 , 1 , nums) ; 
        
    }
};