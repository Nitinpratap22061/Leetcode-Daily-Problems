// Last updated: 10/5/2025, 8:49:17 AM
class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size(); 
        long long diff = 0; 

        for(int i = 0; i < n; i++) { 
            diff += abs(arr[i] - brr[i]); 
        } 

        if(n > 1) { 
            sort(arr.begin(), arr.end()); 
            sort(brr.begin(), brr.end()); 

            long long cost = 0; 

            for(int i = 0; i < n; i++) { 
                cost += abs(arr[i] - brr[i]); 
            } 

            cost += k; 

            return min(diff, cost); 
        } 

        return diff; 
    }
};
