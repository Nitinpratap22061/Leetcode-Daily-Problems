// Last updated: 10/5/2025, 8:57:25 AM
class Solution {
public:

   vector<int>getvectorcount(int n)
   {
     vector<int>vec(10 , 0 ) ; 

     while(n!=0)
     {
        vec[n%10]++;
        n = n/10 ; 
     }
     return vec ; 

   }
    bool reorderedPowerOf2(int n) {

        vector<int>input  = getvectorcount(n) ; 


        for(int power = 0 ; power<=29 ; power++)
        {
            if(input==getvectorcount(1<<power))
            {
                return true ; 
            }
        }

        return false ; 


        
    }
};