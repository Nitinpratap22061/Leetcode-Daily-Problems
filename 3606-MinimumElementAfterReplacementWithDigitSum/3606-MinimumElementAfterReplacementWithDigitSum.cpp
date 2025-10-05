// Last updated: 10/5/2025, 8:49:40 AM
class Solution {
public:
    int minElement(vector<int>& nums) {
        vector<int> help;
        for(int i = 0; i < nums.size(); i++) {
            int res = nums[i];  
            int sum = 0; 
            while(res != 0) {
                sum += res % 10; 
                res /= 10;
            }
            help.push_back(sum); 
        }
        sort(help.begin(), help.end());  
        return help[0]; 
    }
};
