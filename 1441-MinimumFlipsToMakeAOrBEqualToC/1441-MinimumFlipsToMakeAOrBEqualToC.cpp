// Last updated: 10/5/2025, 8:55:40 AM
class Solution {
public:
    int minFlips(int a, int b, int c) {

        int temp1 = (a|b)^c ;
        int ans2 = __builtin_popcount(temp1);
         int temp2 = a&b;; 
        int temp3 = temp1&temp2; 
        int ans1 = __builtin_popcount(temp3) ; 
        return ans1+ans2   ; 

        
    }
};