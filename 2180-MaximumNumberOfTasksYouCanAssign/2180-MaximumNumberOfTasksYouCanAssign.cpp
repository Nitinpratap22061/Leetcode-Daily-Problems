// Last updated: 10/5/2025, 8:53:18 AM
class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength , int mid)
    {
        int pillUsed = 0 ;
        multiset<int>st(begin(workers) , begin(workers)+mid);
        for(int i = mid-1 ; i>=0 ; i--)
        {
            int req = tasks[i];
            auto it = prev(st.end());
            if(*it>=req)
            {
                st.erase(it);
            }
            else if(pillUsed>=pills)
            {
                return false;
            }
            else
            {
                auto weakestit = st.lower_bound(req-strength);
                if(weakestit == st.end())
                {
                    return false;
                }
                st.erase(weakestit);
                pillUsed++;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size();
        int n = workers.size() ; 
        int l = 0 ; 
        int r = min(m,n);
        sort(begin(tasks),end(tasks));
        sort(begin(workers),end(workers),greater<int>());
        int res = 0 ; 
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(check(tasks , workers , pills , strength , mid))
            {
                res = mid ; 
                l = mid+1;
            }
            else
            {
                r = mid-1 ; 
            }
        }
        return res ; 

        
    }
};