// Last updated: 10/29/2025, 4:23:15 PM
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {

        if(x+y<target)
        {
            return false ; 
        }

        queue<int>q ; 
        set<int>visited ; 
        q.push(0) ; 
        visited.insert(0) ; 

        while(!q.empty())
        {
            int a = q.front() ; 
            q.pop() ; 
            if(a==target)
            {
                return true ; 
            }

            int val = a+x ; 

            if(val>=0 && val<=x+y && visited.find(val)==visited.end())
            {
                q.push(val) ; 
                visited.insert(val) ; 
            }
            val = a-x ; 
            if(val>=0 && val<=x+y && visited.find(val)==visited.end())
            {
                q.push(val) ; 
                visited.insert(val) ; 
            }



            val = a-y ; 
            if(val>=0 && val<=x+y && visited.find(val)==visited.end())
            {
                q.push(val) ; 
                visited.insert(val) ; 
            }



            val = a+y ; 
            if(val>=0 && val<=x+y && visited.find(val)==visited.end())
            {
                q.push(val) ; 
                visited.insert(val) ; 
            }
        }

        return false ; 

        
    }
};