// Last updated: 10/5/2025, 8:54:49 AM
class Solution {
public:
 int t[103][103];
    int solve(vector<int>& cuts , int left , int right)
    {
        if(right-left<2)
        {
            return 0 ; 
        }
        if(t[left][right]!=-1)
        {
            return t[left][right];
        }
        int minimumCost = INT_MAX; 
        for(int index = left+1 ; index<=right-1 ; index++)
        {
            int cost = (cuts[right]-cuts[left]) + solve(cuts,left , index) + solve(cuts , index , right);
            minimumCost = min(minimumCost , cost);
            
        }
        return t[left][right] = minimumCost;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(begin(cuts) , end(cuts));
        cuts.insert(begin(cuts) , 0 );
        cuts.push_back(n);
        memset(t,-1,sizeof(t));
       return  solve(cuts ,  0 , cuts.size()-1);
        
    }
};