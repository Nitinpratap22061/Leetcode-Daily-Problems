// Last updated: 10/5/2025, 8:59:34 AM
class Solution {
public:
    bool isPowerOfFour(int n) {

        if(n<=0) return false; 

        int x = log(n) / log(4)  ; 

       if(pow(4,x) ==n)
       {
        return true ; 
       }
       return false;
        
    }
};