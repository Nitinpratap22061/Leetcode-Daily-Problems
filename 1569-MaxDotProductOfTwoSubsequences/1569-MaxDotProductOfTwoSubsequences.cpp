// Last updated: 10/5/2025, 8:55:11 AM
class Solution {
public:
    int n,m;
    int t[501][501];
    int solve(vector<int>& nums1, vector<int>& nums2 , int i , int j)
    {
        if(i==n || j==m)
        {
            return -100000000;
        }
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        int val = nums1[i]*nums2[j];
        int first =solve(nums1,nums2,i+1,j+1)+val;
        int second = solve(nums1,nums2,i,j+1);
        int third = solve(nums1,nums2,i+1,j);

        return t[i][j]=max({val,first,second,third});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size() ; 
        m = nums2.size() ; 
        memset(t,-1,sizeof(t));
        return solve(nums1,nums2,0,0);
        
    }
};