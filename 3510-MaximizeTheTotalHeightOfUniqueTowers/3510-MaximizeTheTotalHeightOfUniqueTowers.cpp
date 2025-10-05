// Last updated: 10/5/2025, 8:49:54 AM
class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
       
        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());
        
        long long sum = 0;
        int prev = maximumHeight[0];  
        
        sum += prev;  

       
        for (int i = 1; i < maximumHeight.size(); i++) {
            int currentHeight = maximumHeight[i];
            
           
            if (currentHeight >= prev) {
                currentHeight = prev - 1;
            }

          
            if (currentHeight < 1) {
                return -1;
            }
            
            sum += currentHeight;
            prev = currentHeight;  
        }

        return sum;
    }
};
