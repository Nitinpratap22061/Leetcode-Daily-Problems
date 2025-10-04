// Last updated: 10/4/2025, 5:45:28 PM
class Solution {
public:
    int n;
    
    bool isAns(int mid, vector<int>& price, int k) {
        int count = 1;
        int last = price[0];
        
        for (int i = 1; i < price.size(); i++) {
            if (price[i] - last >= mid) {
                count++;
                last = price[i];
                if (count >= k) return true; 
            }
        }
        return false;
    }
    
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        
        int low = 0;
        int high = price.back() - price.front(); 
        int res = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isAns(mid, price, k)) {
                res = mid;     
                low = mid + 1;   
            } else {
                high = mid - 1;  
            }
        }
        return res;
    }
};
