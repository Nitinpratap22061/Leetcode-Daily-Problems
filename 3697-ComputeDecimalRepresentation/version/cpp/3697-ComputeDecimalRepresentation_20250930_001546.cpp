// Last updated: 9/30/2025, 12:15:46 AM
class Solution {
public:
    vector<int> decimalRepresentation(int n) {

       int count = 0 ; 
       vector<int>ansi ; 
       while(n!=0)
       {
         int rem = n%10 ; 
         n=  n/10 ; 
         int ans = rem*pow(10,count) ; 
         if(ans!=0)
         {
         ansi.push_back(ans) ; 
         }
         count++ ; 
       }
       reverse(begin(ansi) ,end(ansi)) ; 
       return ansi ; 
        
    }
};