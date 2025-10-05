// Last updated: 10/5/2025, 8:55:57 AM
class Solution {
public:
    // int n;
    // unordered_map<string, int> memo;

    // int solve(vector<int>& arr , int i , int p , int difference) {
    //     if(i >= n) return 0;

    //     string key = to_string(i) + "," + to_string(p);
    //     if(memo.find(key) != memo.end()) return memo[key];

    //     int take = 0;
    //     if(p == -1 || arr[i] - arr[p] == difference) {
    //         take = 1 + solve(arr, i + 1, i, difference);
    //     }
    //     int skip = solve(arr, i + 1, p, difference);

    //     return memo[key] = max(take, skip);
    // }

    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int,int>mp;
        int res = 0 ; 
        for(int i=0 ; i<n ; i++)
        {
            int curr = arr[i];
            int prev = curr-difference;
            int prev_len = mp[prev];
            int curr_len = prev_len+1;
            mp[curr] = curr_len;
            res = max(res , curr_len);
        }
        return res;
    }
};
