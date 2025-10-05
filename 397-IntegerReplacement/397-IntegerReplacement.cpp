// Last updated: 10/5/2025, 8:59:16 AM
class Solution {
public:
int count=0;
     long long solve(long long n)
     {
        while (n > 1) {
            if (n % 2 == 0) {
                n = n / 2;
                count++;
            } else  {
                if ((n + 1) % 4 == 0 && n-1!=2) {
                    n = n + 1;
                    count++;
                   
                }
                else  {
                    n = n - 1;
                    count++;
                    
                }
               
            }
        }
        return count;
     }
    int integerReplacement(int n) {

       
       
        return solve(n);
    }
};