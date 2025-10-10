// Last updated: 10/10/2025, 12:41:07 PM
class Solution {
public:
    int t[100001] ; 
    int solve(vector<int>& energy , int i , int n , int k)
    {
       
        if(i>=n)
        {
            return 0 ; 
        }
        if(t[i]!=-1)
        {
            return t[i] ; 
        }
       int profit =  energy[i]+solve(energy , i+k , n , k) ; 

       return t[i] = profit ;


    }
    int maximumEnergy(vector<int>& energy, int k) {
          int res = INT_MIN ; 
        int n = energy.size() ; 
        memset(t,-1,sizeof(t)) ; 
        for(int i = 0 ; i<n ; i++)
        {
           int ans =  solve(energy , i , n , k) ; 
           res = max(ans , res) ; 
        }
        return res ; 
        
    }
};