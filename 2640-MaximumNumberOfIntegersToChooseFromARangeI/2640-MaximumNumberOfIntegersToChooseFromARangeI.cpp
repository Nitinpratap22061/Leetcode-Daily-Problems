// Last updated: 10/5/2025, 8:51:40 AM
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int>mp;
        int count=0;
        for(auto ele:banned)
        {
            mp[ele]++;
        }
        for(int i=1 ; i<=n ; i++)
        {
            if(mp.find(i)==mp.end())
            {
                maxSum=maxSum-i;
                if(maxSum>=0)
                {
                    count++;
                }
                
            }
           
            
            
            
        }
      return count;
    }
};