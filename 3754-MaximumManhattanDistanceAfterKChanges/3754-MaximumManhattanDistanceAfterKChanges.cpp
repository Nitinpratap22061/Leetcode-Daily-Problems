// Last updated: 10/5/2025, 8:49:05 AM
class Solution {
public:
    int maxDistance(string s, int k) {
        int north = 0 ; 
        int south = 0 ;
        int east = 0 ;
        int west = 0 ;
        int n  = s.length() ; 
        int maxmd = INT_MIN;
        for(int i = 0 ; i<n ; i++)
        {
            if(s[i]=='N') north++;
            else if(s[i]=='S') south++;
            else if(s[i]=='E') east++;
            else if(s[i]=='W')  west++;

            int currmd = abs(south-north)+abs(east-west) ; 

            int step = i+1 ; 
            int wasted = step - currmd ; 
            int extra = 0 ;

            if(wasted!=0)
            {
                 extra = min(2*k,wasted) ; 
            }
            int finalmd = extra+currmd;
            maxmd = max(maxmd,finalmd) ; 
            

        }
        return maxmd;

        
    }
};