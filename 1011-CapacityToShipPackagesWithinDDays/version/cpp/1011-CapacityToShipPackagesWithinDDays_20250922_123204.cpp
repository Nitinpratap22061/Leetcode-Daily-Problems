// Last updated: 9/22/2025, 12:32:04 PM
class Solution {
public:
    int n;
   bool solve(int mid , vector<int>& weights, int days) {
    int sum = 0; 
    for (int i = 0; i < n; i++) {
        if (weights[i] > mid) return false; 
        
        sum += weights[i]; 
        if (sum > mid) {
            sum = weights[i]; 
            days--; 
        }
        if (days == 0) return false; 
    }
    return true; 
}

    int shipWithinDays(vector<int>& weights, int days) {

        n = weights.size();

        

        //minim weight capacity that witll ship all packages in d days ? '
       int low = *max_element(begin(weights), end(weights));
       int high = accumulate(begin(weights), end(weights), 0);
        int res = 0; 

        // inhi low--->high ke bich me ans hoga 

        while(low<=high)
        {
            int mid = low+(high-low)/2 ; 
            if(solve(mid , weights , days))
            {
                res = mid ; 
                high = mid-1;
            }
            else
            {
                low = mid+1 ;
            }
        }

        return res;
        
    }
};