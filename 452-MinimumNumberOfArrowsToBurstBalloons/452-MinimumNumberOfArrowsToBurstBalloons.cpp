// Last updated: 10/5/2025, 8:58:57 AM
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(begin(points),end(points));
        int count=1;
        vector<int> prev=points[0];
        for(int i=1;i<n;i++)
        {
            int currsp=points[i][0];
            int currep=points[i][1];
            int prevsp=prev[0];
            int prevep=prev[1];
            if(currsp>prevep)
            {
                count++;
                prev=points[i];
            }
            else
            {
                //update prev since overlap
                prev[0]=max(prevsp,currsp);
                prev[1]=min(prevep,currep);
            }

        }
        return count;
        
    }
};