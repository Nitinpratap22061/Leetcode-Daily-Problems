// Last updated: 10/5/2025, 9:01:47 AM
class Solution {
public:
     unordered_map<string , bool>dp ; 
      
    bool solve(string s1, string s2 )
    {
        if(s1==s2)
        {
            return true ; 
        }
        if(s1.length()!=s2.length())
        {
            return false ; 
        }
        string key = s1 +"#"+s2 ; 
        if(dp.find(key)!=dp.end())
        {
            return dp[key] ; 
        }


      int n = s1.length();
        bool res = false ; 
        for(int cut = 1 ; cut<n ; cut++)
        {
           

            //two option 
            bool swapped = solve(s1.substr(0,cut) , s2.substr(n-cut , cut) ) && solve(s1.substr(cut,n-cut),s2.substr(0 , n-cut)) ; 

            if(swapped == true)
            {
                res = true ;
                break ;
            }
            bool notswapped = solve(s1.substr(0,cut) , s2.substr(0 , cut)) && solve(s1.substr(cut , n-cut) , s2.substr(cut , n-cut)) ;
            if(notswapped == true)
            {
                res = true ;
                break ;
            }



        }

        return dp[key] = res ;
    }
    bool isScramble(string s1, string s2) {
    
           dp.clear() ; 
        return solve(s1,s2 ) ; 

       
        
    }
};