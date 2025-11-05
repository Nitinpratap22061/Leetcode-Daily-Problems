// Last updated: 11/5/2025, 5:49:28 PM
class Solution {
public:

    int t[301][301] ; 
    int solve(int i , int j , vector<int>& nums)
    {
        if(i>j)
        {
            return 0 ; 
        }
         
         if(t[i][j]!=-1)
         {
            return t[i][j] ; 
         }
         
        int maxi = INT_MIN ; 
        for(int k = i ; k<= j ; k++)
        {
            //kaam 
            int cost = nums[i-1] * nums[k] * nums[j+1] + solve(i , k-1 , nums) + solve(k+1 , j , nums) ; 
            maxi = max(maxi , cost) ; 

        }
        return t[i][j] = maxi ; 
    }
    int maxCoins(vector<int>& nums) {
           //int n = nums.size() ;
        nums.insert(nums.begin(), 1);
       nums.push_back(1);
       int n  = nums.size() ; 

       
        memset(t , -1 , sizeof(t)) ; 
        return solve(1 , n-2 , nums) ; 


        
    }
};