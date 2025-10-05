// Last updated: 10/5/2025, 8:51:33 AM
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;
        long long minele = LLONG_MAX;

        for (auto& x : basket1) {
            mp[x]++;
            minele = min(minele, (long long)x);
        }

        for (auto& x : basket2) {
            mp[x]--;
            minele = min(minele, (long long)x);
        }

        vector<long long> helper;

        for (auto& ele : mp) {
            int cost = ele.first;
            int count = ele.second;

            if (count % 2 != 0) {
                return -1; 
            }

            for (int i = 0; i < abs(count) / 2; i++) {
                helper.push_back(cost);
            }
        }

       
        sort(helper.begin(), helper.end());

        long long totalCost = 0;
        int n = helper.size();

        
        for (int i = 0; i < n / 2; i++) {
            totalCost += min(helper[i], 2 * minele);
        }

        return totalCost;
    }
};
