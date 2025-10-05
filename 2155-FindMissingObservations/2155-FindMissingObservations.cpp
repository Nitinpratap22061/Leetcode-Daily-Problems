// Last updated: 10/5/2025, 8:53:24 AM
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int size = rolls.size();
        int sum = 0;
        vector<int> v;

        for (int ele : rolls) {
            sum += ele;
        }

        int total_size = size + n;
        int total_sum_needed = mean * total_size;
        int sum_of_missing_rolls = total_sum_needed - sum;

        if (sum_of_missing_rolls < n || sum_of_missing_rolls > 6 * n) {
            return v;
        }

        int base_value = sum_of_missing_rolls / n;
        int remainder = sum_of_missing_rolls % n;

        v.resize(n, base_value);

        for (int i = 0; i < remainder; ++i) {
            v[i]++;
        }

        return v;
    }
};
