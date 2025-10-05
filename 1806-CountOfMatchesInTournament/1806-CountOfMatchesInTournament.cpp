// Last updated: 10/5/2025, 8:54:23 AM
class Solution {
public:
    int numberOfMatches(int n) {
        int sum=0;
        int matches;
           while(n>1) {
            if(n%2==0){
                matches=n/2;
                n=n-matches;
                sum=sum+matches;
            }
            matches=(n-1)/2;
            n=n-matches;
            sum=sum+matches;
        }
        return sum;
        
    }
};