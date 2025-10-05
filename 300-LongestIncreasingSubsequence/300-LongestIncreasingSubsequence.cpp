// Last updated: 10/5/2025, 8:59:45 AM

class Solution {
public:
  int t[2501][2501];
      int solve(vector<int>& nums , int i,int p)
      {
        int n=nums.size();
        int take =0;
        if(i>=n)
        {
            return 0;
        }
       int offset = p+1;
        if(t[i][offset]!=-1)
        {
            return t[i][offset];
        }
        //take
        if(p==-1 || nums[p] < nums[i])
        {
           
         take = 1+ solve(nums,i+1,i);
        }
        
        int skip= solve(nums,i+1,p);
        return t[i][offset] =  max(take,skip);

      }
    int lengthOfLIS(vector<int>& nums) {
        int i =0;
        memset(t,-1,sizeof(t));
       return solve(nums ,i,-1);
      
    }
};
