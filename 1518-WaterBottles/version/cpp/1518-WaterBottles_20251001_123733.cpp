// Last updated: 10/1/2025, 12:37:33 PM
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
