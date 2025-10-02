// Last updated: 10/2/2025, 4:55:25 PM
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {

         int fullBottles = 0  ; 
         int ans = numBottles ; 
         int emptyBottles = numBottles ; 
         while(emptyBottles>=numExchange)
         {
            emptyBottles -= numExchange ; 
            fullBottles +=1 ; 
            ans+=1 ; 
            numExchange++ ; 
         }
         emptyBottles +=fullBottles ; 
         if(emptyBottles>=numExchange)
         {
            ans+=1 ; 
          }
         return ans ; 
        
    }
};