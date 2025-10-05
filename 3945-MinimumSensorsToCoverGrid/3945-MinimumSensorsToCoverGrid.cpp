// Last updated: 10/5/2025, 8:48:27 AM
class Solution {
public:
     
        int minSensors(int n, int m, int k) {
    int d = 2 * k + 1;
    int rows = (n + d - 1) / d; 
    int cols = (m + d - 1) / d;
    return rows * cols;
}

    
};