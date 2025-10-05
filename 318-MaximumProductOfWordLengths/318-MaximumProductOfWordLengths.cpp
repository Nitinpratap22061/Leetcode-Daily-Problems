// Last updated: 10/5/2025, 8:59:40 AM
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> bitmasks(n);
        for (int i = 0; i < n; ++i) {
            int mask = 0;
            for (char c : words[i]) {
                mask |= 1 << (c - 'a');
            }
            bitmasks[i] = mask;
        }

       
        int maxProduct = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((bitmasks[i] & bitmasks[j]) == 0) {
                    int product = words[i].length() * words[j].length();
                    maxProduct = max(maxProduct, product);
                }
            }
        }

        return maxProduct;
    }
};
