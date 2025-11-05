// Last updated: 11/5/2025, 1:31:44 PM
class Solution {
public:
      int target ; 
      int  t[201][20001];
    bool solve(int n , vector<int>& arr , int i , int sum)
    {
        if(i>=n)
        {
            return false ; 
        }
        if(t[i][sum]!=-1)
        {
            return t[i][sum] ; 
        }
        if(sum==target)
        {
            return true ; 
        }   
        //two option 
        int take = solve(n , arr , i+1 , sum+arr[i]) ; 
        int skip = solve(n , arr , i+1 , sum) ; 

        return t[i][sum] = take||skip ; 
    }
    bool canPartition(vector<int>& arr) {

             int n = arr.size() ; 
          int totalSum = 0 ; 
        for(auto ele : arr)
        {
            totalSum+=ele ; 
        }
        if(totalSum%2!=0)
        {
            return false ; 
        }
        target = totalSum/2 ; 
        memset(t,-1,sizeof(t)) ; 
        return solve(n , arr , 0 , 0);
        
    }
};