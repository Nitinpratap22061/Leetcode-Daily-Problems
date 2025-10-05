// Last updated: 10/5/2025, 8:51:35 AM
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size() ; 
        int m = n-1 ;
        vector<int>psum(m,0);
        for(int i = 0 ; i<m ; i++)
        {
            psum[i] = weights[i] + weights[i+1];
        }
        sort(begin(psum) , end(psum));
        long long maxsum  = 0 ;
        long long minsum = 0 ;
        for(int i = 0 ; i<k-1 ; i++)
        {
            minsum +=psum[i];
            maxsum+=psum[m-1-i];
        }
        return maxsum - minsum ;
        
    }
};