// Last updated: 10/10/2025, 1:36:35 PM
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {

        int n = skill.size() ; 
        int m = mana.size() ; 

        vector<long long>ans(n , 0) ; 

        for(int j = 0 ; j<m ; j++)
        {
            ans[0] +=skill[0]*mana[j] ; 
            for(int i = 1 ; i<n ; i++)
            {
               ans[i]  = max(ans[i] , ans[i-1])+ 1LL * mana[j]*skill[i] ; 
            }

            //sync correct 
            for(int i = n-1 ; i>0 ; i--)
            {
                ans[i-1] = (ans[i])- 1LL* mana[j]*skill[i] ; 
            }
        }

        return ans[n-1] ; 
        
    }
};