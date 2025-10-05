// Last updated: 10/5/2025, 8:59:30 AM
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>help;
        vector<int>ans;
        int i=0;
        int j=0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n1=nums1.size();
        int n2=nums2.size();
        int maxi=max(n1,n2);
        while(i<n1 && j<n2)
        {
            if(nums1[i]==nums2[j])
            {
                help.insert(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j])
            {
                i++;
            }
            else if(nums1[i]>nums2[j])
            {
                j++;
            }
        }
        for(int  element:help)
        {
          ans.push_back(element);
        }
        return ans;
        
    }
};