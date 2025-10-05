// Last updated: 10/5/2025, 8:52:09 AM
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int max=0;  
        int ans=-1;
        vector<int>help; 
        vector<int>result;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            int ele=nums[i];
            if(ele%2==0)
            {
                mp[ele]++;
            }
        }
        for(auto itr:mp)
        {
            help.push_back(itr.second);
        }
        if(help.size()==0)
        {
            return ans;
        }
        sort(help.begin(),help.end());
        max=help[help.size()-1];
        for(auto itr:mp)
        {
            if(itr.second==max)
            {
                result.push_back(itr.first);

            }
        }
        sort(result.begin(),result.end());
        if(result.size()>=1) return result[0];
        else return ans;

        
    }
};