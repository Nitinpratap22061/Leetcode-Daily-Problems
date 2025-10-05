// Last updated: 10/5/2025, 8:49:00 AM
class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {

        sort(begin(pizzas) , end(pizzas));

        int n = pizzas.size() ; 
        int days = n/4 ; 
         
         long long res = 0 ;
        int curridx = n-1 ; 

        //first let eat highest for odd 
        for(int day =1 ; day<=days ; day+=2)
        {
            res += pizzas[curridx--];
        }
        curridx--;
        //even smax alternante le lo 
        for(int day = 2 ; day<=days ; day+=2)
        {
            res += pizzas[curridx] ; 
            curridx -= 2 ;  
        }

        return res ; 
        
    }
};