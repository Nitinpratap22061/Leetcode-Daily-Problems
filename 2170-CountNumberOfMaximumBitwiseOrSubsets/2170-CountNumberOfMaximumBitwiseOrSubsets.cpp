// Last updated: 10/5/2025, 8:53:20 AM
class Solution {
public:
    int n ; 
     int t[20][1000001];
    int solve(int i , vector<int>& nums , int curror , int maxor)
    {

       if(i==n)
         {
            if(maxor == curror)
            {
                return 1;
            }
            return 0;
         }

         if(t[i][curror]!=-1)
         {
            return t[i][curror];
         }


        int take = solve(i+1 , nums , nums[i]|curror , maxor) ; 
        int skip = solve(i+1 , nums , curror , maxor) ; 
        

        return t[i][curror] = take+skip ; 

    }
    int countMaxOrSubsets(vector<int>& nums) {
           memset(t,-1,sizeof(t));

        n = nums.size() ; 

        //while doing or number increase or increase or same never decrease ; 
        int maxbitor = 0 ;  
        for(auto ele : nums)
        {
            maxbitor = maxbitor|ele ; 
        }
        //now count subset which or maxbitwise or 

        return solve(0 , nums , 0 , maxbitor) ; 


        
    }
};