// Last updated: 10/5/2025, 9:03:02 AM
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Get the sizes of both input arrays.
        int n = nums1.size();
        int m = nums2.size();
             int mid1,mid2;

        // Merge the arrays into a single sorted array.
        vector<int> merged;
        for (int i = 0; i < n; i++) {
            merged.push_back(nums1[i]);
        }
        for (int i = 0; i < m; i++) {
            merged.push_back(nums2[i]);
        }

        // Sort the merged array.
        sort(merged.begin(), merged.end());

        int total=merged.size();
        if(total%2!=0){

            return merged[int(total/2)];

        }
        else{
         mid1=merged[total/2];
         mid2=merged[(total/2)-1];
        return double((mid1+mid2)/2.0);
        }
        
    }
};