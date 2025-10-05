// Last updated: 10/5/2025, 8:57:39 AM
class Solution {
public:
    vector<vector<double>>vec = {{100.0,0.0} , {75.0,25.0} , {50.0,50.0} , {25.0,75.0}};
    unordered_map<string,double>mp;
    double solve(int a , int b)
    {
        if(a<=0&&b<=0)
        {
            return 0.5;
        }
        if(a<=0)
        {
            return 1.0 ; 
        }
        if(b<=0)
        {
            return 0.0 ; 
        }
        string key = to_string(a) + "," + to_string(b);
        if(mp.count(key))
        {
            return mp[key];
        }
        double res = 0.0 ;
        for(auto &v:vec)
        {
            int a_taken = v[0];
            int b_taken = v[1];

            res+=solve(a-a_taken , b-b_taken);
        }
        return mp[key]=0.25*res;
        
    }
    double soupServings(int n) {
        if(n>4275)
        {
            return 1.0;
        }

        return solve(n,n);


        
    }
};