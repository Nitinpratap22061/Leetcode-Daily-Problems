// Last updated: 10/5/2025, 8:51:57 AM
class Solution {
public:
    typedef long long ll;
    long long t[102][10001];
    long long solve(int robotidx , int factoryidx , vector<int>& robot , vector<int>& positions)
    {
        if(robotidx>=robot.size())
        {
            return 0 ; 
        }
        if(factoryidx>=positions.size())
        {
            return 1e12 ; 
        }
        if(t[robotidx][factoryidx]!=-1)
        {
            return t[robotidx][factoryidx];
        }
        ll take = abs(robot[robotidx]-positions[factoryidx])+solve(robotidx+1 , factoryidx+1 , robot , positions);
        ll skip = solve(robotidx , factoryidx+1 , robot , positions);

        return t[robotidx][factoryidx]=min(take,skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(factory.begin() , factory.end());
        sort(robot.begin() , robot.end());

        vector<int>positions ; 
        for(int i = 0 ; i<factory.size() ; i++)
        {
            int limit = factory[i][1];
            int pos = factory[i][0];
            for(int j = 0 ; j<limit ; j++)
            {
                positions.push_back(pos);
            }
        }
        memset(t,-1,sizeof(t));
        return solve(0 , 0 , robot , positions);
        
    }
};