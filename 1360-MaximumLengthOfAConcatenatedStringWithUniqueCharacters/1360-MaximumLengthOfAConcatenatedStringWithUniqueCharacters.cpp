// Last updated: 10/5/2025, 8:55:52 AM
class Solution {
public:

   bool hasDuplicate(string &s1 , string &s2)
   {
      int arr[26] = {0} ;
      for(auto &ch : s1)
      {
        if(arr[ch-'a'] >0)
        {
            return true ;
        }
        arr[ch-'a']++;
      }

      for(auto &ch : s2)
      {
        if(arr[ch-'a'] > 0)
        {
            return true ;
        }
      }
      return false;
   }
    int solve(vector<string>& arr , int i , string temp , int n)
    {
        if(i>=n)
        {
            return temp.length() ; 
        }
        int include = 0 ;
        int exclude = 0;

        if(hasDuplicate(arr[i] , temp))
        {
            exclude = solve(arr , i+1 , temp , n );
        }
        else
        {
            include = solve(arr , i+1 , temp+arr[i] , n);
            exclude = solve(arr , i+1 , temp , n );
        }
        return max(include , exclude) ;
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size() ; 
        string temp = "";
        return solve(arr , 0 , temp , n);
    }
};