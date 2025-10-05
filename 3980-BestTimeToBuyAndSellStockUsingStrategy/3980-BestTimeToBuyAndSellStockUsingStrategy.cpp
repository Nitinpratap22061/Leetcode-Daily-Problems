// Last updated: 10/5/2025, 8:48:17 AM
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = strategy.size(); 
        long long baseProfit = 0;

        for (int i = 0; i < n; i++) {
            baseProfit += 1LL * prices[i] * strategy[i];
        }

        
        vector<long long> prefOld(n+1, 0), prefPrice(n+1, 0);
        for (int i = 0; i < n; i++) {
            prefOld[i+1] = prefOld[i] + 1LL * prices[i] * strategy[i];
            prefPrice[i+1] = prefPrice[i] + prices[i];
        }

        long long ans = baseProfit;

        int i = 0, j = 0;
        while (j < n) {
            if (j - i + 1 < k) {
                j++;
            }
            else if (j - i + 1 == k) {
               
                long long oldContribution = prefOld[j+1] - prefOld[i];

               
                long long newContribution = prefPrice[j+1] - prefPrice[i + k/2];

                long long newProfit = baseProfit - oldContribution + newContribution;
                ans = max(ans, newProfit);

                
                i++;
                j++;
            }
        }

        return ans;
    }
};
