// Last updated: 10/5/2025, 8:49:44 AM
class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        int prev = 0 ; 
        vector<int>ans;
        for(int i=1;i<height.size() ; i++)
        {
           if(height[prev] > threshold)  
           {
              ans.push_back(i);
           }
           prev++;
        }
        return ans;
    }
};