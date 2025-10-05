// Last updated: 10/5/2025, 8:55:56 AM
class Solution {
public:
    int ans = 0;
    vector<pair<int, int>> sol;

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            string help = to_string(nums[i]);
            int fans = 0;
            
            for (int j = 0; j < help.size(); j++) {
                char res = help[j];
                int mappedDigit = mapping[res - '0']; 
                fans = fans * 10 + mappedDigit; 
            }
            
            sol.push_back({fans, i});
        }
        
   
        sort(sol.begin(), sol.end());
        
        vector<int> result;
        for (const auto& p : sol) {
            result.push_back(nums[p.second]); 
        }
        
        return result;
    }
};
