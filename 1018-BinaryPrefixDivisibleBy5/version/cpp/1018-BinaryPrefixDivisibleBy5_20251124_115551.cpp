// Last updated: 11/24/2025, 11:55:51 AM
class Solution {
public:
vector<bool> prefixesDivBy5(vector<int>& nums) {
vector<bool> ans;
int current = 0;


    for (int bit : nums) {
        current = (current * 2 + bit) % 5;
        ans.push_back(current == 0);
    }
    
    return ans;
}

};
