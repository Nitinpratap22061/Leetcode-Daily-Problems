// Last updated: 10/5/2025, 9:02:54 AM
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() ; 

        int left = 0 ; 
        int right = n-1 ; 

        int maxArea = INT_MIN; 

        while(left<right)
        {
            int currArea = min(height[left] , height[right]) * (right - left) ; 
            maxArea = max(maxArea , currArea) ; 

            if(height[left] > height[right])
            {
                right -- ; 
            }
            else
            {
                left++ ; 
            }
        }

        return maxArea ; 
        
    }
};