// Last updated: 10/5/2025, 8:48:20 AM
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {


        int minTime = INT_MAX;  

        for (int i = 0; i < landStartTime.size(); ++i) {
            for (int j = 0; j < waterStartTime.size(); ++j) {
                
                
                int start1 = landStartTime[i];
                int end1 = start1 + landDuration[i];
                int start2 = max(waterStartTime[j], end1);  
                int finish1 = start2 + waterDuration[j];

               
                int start3 = waterStartTime[j];
                int end2 = start3 + waterDuration[j];
                int start4 = max(landStartTime[i], end2);  
                int finish2 = start4 + landDuration[i];

                int ans = min(finish1,finish2) ; 
                minTime = min(minTime, ans);
            }
        }

        return minTime;
        
    }
};