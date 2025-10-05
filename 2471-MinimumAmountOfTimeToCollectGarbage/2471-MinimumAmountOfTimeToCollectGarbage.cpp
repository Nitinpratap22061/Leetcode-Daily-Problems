// Last updated: 10/5/2025, 8:52:13 AM
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int n = garbage.size() ; 
        int G_idx = 0;
        int M_idx = 0;
        int P_idx = 0;
        int time = 0 ; 
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j<garbage[i].length() ; j++)
            {
                if(garbage[i][j] == 'M')
                {
                    M_idx = i;
                    time++;
                }
                else if(garbage[i][j] == 'P')
                {
                    P_idx = i;
                    time++;
                }
                else if(garbage[i][j] == 'G')
                {
                    G_idx = i;
                    time++;
                }
              
            }
        }
        //prefix sum 
        for(int i=1 ; i<travel.size() ;i++)
        {
            travel[i]+=travel[i-1];
        }
        time+=G_idx>0?travel[G_idx-1]:0;
        time+=P_idx>0?travel[P_idx-1]:0;
        time+=M_idx>0?travel[M_idx-1]:0;

        return time;
        
    }
};