// Last updated: 10/7/2025, 11:07:33 PM

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        /*

        Story Points : -
        1>map--->kisi lake me phli baar barish kb 
        2>zero days store (set since sorted ) ;
        3>greedily pick the closest empty day after the rain
        */
        int n = rains.size() ; 

        unordered_map<int,int>mp;
        set<int>st;
        vector<int>ans(n,1);
        for(int i = 0 ; i<n ; i++)
        {
            int lake = rains[i] ; 
            if(lake==0)
            {
                st.insert(i) ; 
            }
            else
            {
                ans[i] = -1 ; 
                if(mp.count(lake)) // already water
                {
                    auto it = st.lower_bound(mp[lake]);
                    if(it==st.end()) // not able to dry
                    {
                   return {} ; 
                    }
                    int day = *it ;
                    ans[day] = lake ; 

                    st.erase(it) ; 
                }
                mp[lake] = i ; 
            }
        }
          return ans ; 

    }
};
