// Last updated: 9/22/2025, 6:19:00 PM
class Solution {
public:
     int n ; 

    bool solve(vector<int>& time, int totalTrips , long long mid)
    {
        //kya hm mid time me trip = total trip kr skte 
        long long  trip = 0 ; 
        for(int i = 0 ; i<n ; i++)
        {
            trip+=(mid/(long long)time[i]) ;
            if(trip>=totalTrips)
            {
                return true ; 
            } 
        }
        return trip>=totalTrips ; 
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        n = time.size() ; 
        long long res  = -1; 
        //hmko min time btana to complete at least tottla trip 
        long long low = 1 ; 
        int maxtime = *max_element(begin(time) , end(time)) ; 
        long long  high = (long long)maxtime * (long long)totalTrips ; 
        while(low<=high)
        {
            long long mid = low+(high-low)/2 ; 
            if(solve(time , totalTrips , mid))
            {
                res = mid ; 
                high = mid-1 ; 
            }
            else
            {
                low = mid+1 ; 
            }
        }
        
        return res ; 
        
    }
};