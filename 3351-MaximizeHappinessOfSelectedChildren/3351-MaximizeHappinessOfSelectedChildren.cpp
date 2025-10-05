// Last updated: 10/5/2025, 8:50:20 AM
class Solution {
public:
       long long  sum=0;
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        int help = 1;
        sort(happiness.begin(),happiness.end());
        while(k>0)
        {
            happiness[n-help] = (happiness[n-help]) - (help-1) ;
            if(happiness[n-help] < 0)
            {
                happiness[n-help] = 0;
            }
           sum=sum+happiness[n-help];
           help++;
           k--;
           
        }
        return sum;
        
    }
};