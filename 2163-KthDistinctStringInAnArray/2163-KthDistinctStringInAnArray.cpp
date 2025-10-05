// Last updated: 10/5/2025, 8:53:21 AM
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        for(auto ele : arr)
        {
            mp[ele]++;
        }
        for(int i=0 ; i<arr.size() ;i++)
        {
            if(mp[arr[i]]==1)
            {
                k--;
            }
            if(k==0)
            {
                return arr[i];
            }

        }
        return "";
        
    }
};