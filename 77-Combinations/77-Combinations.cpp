// Last updated: 10/5/2025, 9:01:57 AM
class Solution {
public:

 void solve(int start , int k , vector<int>&temp ,  vector<vector<int>>&res , int n)
 {
    if(k==0)
    {
        res.push_back(temp);
        return;
    }
    if(start > n) return ;
    temp.push_back(start) ;//le rhe
    //explore
    solve(start+1 , k-1 , temp , res , n);

    // khali to kro to explore more path
    temp.pop_back();
    //again explore
    solve(start+1 , k , temp , res , n) ;

    return;
 }
    vector<vector<int>> combine(int n, int k) {
       vector<vector<int>>res;
        vector<int>temp;
         solve(1,k,temp,res , n);
        return res;
    }
};