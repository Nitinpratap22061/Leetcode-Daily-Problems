// Last updated: 10/5/2025, 8:54:21 AM
class Solution {
public:
    int totalMoney(int n) {
        
       int res=0;
       int monday_money=1;
       while(n>0){
           int money=monday_money;
           for(int i=1;i<=min(n,7);i++){
               res+=money;
               money++;
           } 
           n-=7;
           monday_money++;
       }
       return res;
        
    }
};