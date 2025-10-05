// Last updated: 10/5/2025, 8:51:41 AM
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int ans=-1;
        int n=min(n1,n2);
        int j=0;
        int i=0;
         while(i<n1 && j<n2)
        {
             if(nums1[i]==nums2[j])
          {
               ans=nums1[i];
              break;
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
        return ans;
        
    }
};