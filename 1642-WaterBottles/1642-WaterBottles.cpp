// Last updated: 10/5/2025, 8:54:57 AM
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        int empty = numBottles;

        while (empty >= numExchange) {
            int newBottles = empty / numExchange;  
            total += newBottles;                  
            empty = empty % numExchange + newBottles; 
        }

        return total;
    }
};
