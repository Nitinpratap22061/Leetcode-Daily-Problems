// Last updated: 11/24/2025, 12:01:54 PM
class Solution {
public:
bool solve(const string &num) {
int val = 0;
for (char c : num) {
val = (val * 2 + (c - '0')) % 5;
}
return val == 0;
}

vector<bool> prefixesDivBy5(vector<int>& nums) {
    int n = nums.size();
    vector<bool> ans;
    string helper = "";

    for (int ele : nums) {
        // convert correctly
        char ch = '0' + ele;
        helper += ch;

        // check current prefix
        ans.push_back(solve(helper));
    }

    return ans;
}


};
