// Last updated: 10/5/2025, 8:59:24 AM
class Solution {
public:
    typedef pair<int,pair<int,int>>P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P,vector<P>,greater<P>>pq; ; 
        vector<vector<int>>result ; 
        int m = nums1.size() ;
        int n = nums2.size() ; 
        set<pair<int,int>>visited ;
        int isum = nums1[0] + nums2[0] ; 
        pq.push({isum , {0,0}}) ;
        visited.insert({0,0}) ;
        while(k-- && !pq.empty())
        {
            int sum = pq.top().first ; 
            int i = pq.top().second.first ; 
            int j = pq.top().second.second ; 
            pq.pop() ; 
            result.push_back({nums1[i] , nums2[j]});

            if(j+1<n && visited.find({i,j+1})==visited.end())
            {
                pq.push({nums1[i]+nums2[j+1] , {i,j+1}});
                visited.insert({i,j+1});
            }
            if(i+1<m && visited.find({i+1,j})==visited.end())
            {
                pq.push({nums1[i+1]+nums2[j] , {i+1,j}});
                visited.insert({i+1,j});

            }


        }
        return result ; 
        
    }
};