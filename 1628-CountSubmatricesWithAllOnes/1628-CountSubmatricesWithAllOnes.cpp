// Last updated: 10/5/2025, 8:55:00 AM

class Solution {
public:
   
    long long nC2(int n) {
        return 1LL * n * (n - 1) / 2;
    }

    
    long long oneFilledSubarray(vector<int>& nums) {
        int count = 0;
        vector<int> helper;
        int continuous = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                continuous++;
            } else {
                if (continuous > 0) {
                    helper.push_back(continuous);
                    continuous = 0;
                }
            }
        }
        if (continuous > 0) helper.push_back(continuous);

        long long res = 0;
        for (auto len : helper) {
            res += len;        
            res += nC2(len);  
        }
        return res;
    }

   
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        long long res = 0;

      
        for (int i = 0; i < n; i++) {
            vector<int> t(m, 1);
           
            for (int j = i; j < n; j++) {
                for (int col = 0; col < m; col++) {
                    t[col] = t[col] & mat[j][col];  
                }
                res += oneFilledSubarray(t);
            }
        }
        return (int)res;
    }
};
