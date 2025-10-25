// Last updated: 10/25/2025, 8:48:34 PM
class Solution {
public:

    
    string maxSumOfSquares(int num, int sum) {

        //recursion ke help se try to solve 
        //ek kaam krte let solve for num/2 because uske aage to ulta hi pattern aa raha
        //eg: - num = 2 sum = 17
    //     1 16
    //     2 15
    //     3 14
    // 4 13
    // 5 12
    // 6 11 
    // 7 10
    // 8 9
    // now reverse repeat 
    // 9 8 
    // 10 7 

       if(sum>9*num)
       {
           return "" ; 
       }

        string fres = "" ; 
        for(int i = 0 ; i<num ; i++)
            {
                int helper = min(9 , sum) ;
                
                fres += to_string(helper) ;  
                sum = sum - helper ; 
            }
        if(sum>0)
        {
            return "" ; 
        }
        return fres ; 

        
    }
};