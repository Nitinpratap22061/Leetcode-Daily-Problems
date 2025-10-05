// Last updated: 10/5/2025, 9:01:44 AM

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, idx = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] < nums2[j])
            {
                nums1[idx] = nums2[j];
                j--;
                idx--;
            }
            else
            {
                nums1[idx] = nums1[i];
                i--;
                idx--;
            }
        }
        while (i >= 0)
            nums1[idx--] = nums1[i--];
        while (j >= 0)
            nums1[idx--] = nums2[j--];
    }
};