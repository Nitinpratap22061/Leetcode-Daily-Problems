// Last updated: 10/5/2025, 8:51:49 AM
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin() , skill.end());
        long long i;
        long long n=skill.size();
        long long j;
       long long sum=skill[0]+skill[n-1];
        long long sum1=0;
        long long res=skill[0]*skill[n-1];

        for(i=1,j=n-2 ; i<j ; i++,j--)
        {
           sum1=skill[i]+skill[j]; 
           if(sum!=sum1)
           {
            return -1;
           }
           res=res+(skill[i]*skill[j]);

        }
        return res;
        
    }
};