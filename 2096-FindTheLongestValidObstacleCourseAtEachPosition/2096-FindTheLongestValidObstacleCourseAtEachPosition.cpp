// Last updated: 10/5/2025, 8:53:32 AM
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size() ; 
        vector<int>LIS;
        vector<int>res(n) ; 
        for(int i = 0 ; i<n ; i++)
        {
            int idx = upper_bound(begin(LIS),end(LIS),obstacles[i]) - begin(LIS) ; 
            if(idx==LIS.size())
            {
                LIS.push_back(obstacles[i]);
            }
            else
            {
                LIS[idx] = obstacles[i];
            }
            res[i] = idx+1 ; 
        }
        return res ; 
        
    }
};