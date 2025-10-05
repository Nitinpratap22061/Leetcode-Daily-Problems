// Last updated: 10/5/2025, 8:51:38 AM
class Solution {
public:

    bool isPossible(vector<int>& ranks , long long mid , int cars )
     {
        int carCount = 0 ;
        for(int i =0 ; i<ranks.size() ; i++)
        {
            carCount += sqrt(mid/ranks[i]);
            if(carCount>=cars)
            {
                return true;
            }
        }
        return false;
     }
    long long repairCars(vector<int>& ranks, int cars) {
        long long  l = 1 ; 
        long long res = 0;
        long long  maxi = *max_element(begin(ranks) , end(ranks));
        long long r = maxi*cars*cars;
        while(l<=r)
        {
            long long mid = l + (r-l)/2;
            if(isPossible(ranks , mid , cars))
            {
                res = mid ; 
                r = mid-1 ;
            }
            else
            {
                l=mid+1 ;
            }
        }
        return res;
    }
};