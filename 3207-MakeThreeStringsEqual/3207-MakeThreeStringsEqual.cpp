// Last updated: 10/5/2025, 8:50:42 AM
class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int l = s1.length();
        int k = s2.length(); 
        int w = s3.length(); 

        int n = min({l, k, w});
        int j = n - 1;
        int count = 0;

      
        int i;
        for (i = 0; i <= j; i++) {
            if (s1[i] != s2[i] || s2[i] != s3[i] || s3[i] != s1[i]) {
                break; 
            }
        }


        if (i == 0) return -1;

        
        return (l - i) + (k - i) + (w - i);
    }
};
