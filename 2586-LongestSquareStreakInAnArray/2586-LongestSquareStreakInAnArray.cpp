// Last updated: 10/5/2025, 8:51:47 AM
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int , int > mp;
        sort(nums.begin() , nums.end());
        int maxstreak =0 ;
        for(auto num : nums)
        {
            int root = (int)sqrt(num);

            if(root * root == num && mp.find(root)!=mp.end())
            {
                mp[num] = mp[root]+1;
            }
            else
            {
                mp[num]=1;
            }
            maxstreak = max(maxstreak , mp[num]);
        }

        if(maxstreak>=2)
        {
            return maxstreak;
        }
        return -1;


    }
};