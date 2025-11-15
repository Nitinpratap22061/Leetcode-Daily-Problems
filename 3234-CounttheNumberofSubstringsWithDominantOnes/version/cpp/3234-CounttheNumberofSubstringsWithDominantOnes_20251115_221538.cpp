// Last updated: 11/15/2025, 10:15:38 PM
class Solution {
public:
    int numberOfSubstrings(string s) {
       int n = s.length() ; 

       //precompute number of one like how many 1 till index i ; 
       vector<int>pre(n , 0) ; 

       pre[0] = (s[0]=='1'?1:0) ; 

       for(int i = 1 ; i<n ; i++)
       {
         pre[i] = pre[i-1] + (s[i]=='1'?1:0) ; 
       }

       int res = 0 ; 

       for(int i = 0 ; i<n ; i++)
       {
        for(int j = i ; j<n ; j++)
        {
            int ones = pre[j]-(i-1>=0?pre[i-1]:0) ; 
            int zero = (j-i+1)-ones ; 

            if(zero*zero > ones)
            {
               //shift 
               int wasteidx = zero*zero - ones ; 
               j+=wasteidx-1 ; 
            }
            else if(zero*zero == ones)
            {
                res+=1 ; 
            }
            else
            {
                res+=1 ; 
                int k = sqrt(ones)-zero  ; 
                int next = j+k ; 

                if(next>=n)
                {
                    res+=(n-j-1) ; 
                    break ; 
                }
                else
                {
                    res+=k ; 
                }
                j = next ; 
            }
        }
       }

       return res; 

    }
};