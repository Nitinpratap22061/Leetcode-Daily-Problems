// Last updated: 10/5/2025, 8:50:07 AM
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(begin(meetings) , end(meetings));
        int start = 0 ;
        int end = 0 ;
        int res = 0;
        for(auto &meet : meetings)
        {
            if(meet[0] > end)
            {
                res += meet[0] - end - 1 ;
            }
            end = max(end , meet[1]);
        }
        if(days>end)
        {
            res+=days-end;
        }
        return res;
        
    }
};