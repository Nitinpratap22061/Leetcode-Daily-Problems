// Last updated: 10/5/2025, 8:50:30 AM
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {

        auto lambda = [](vector<int> &point1 , vector<int>& point2)
        {
            if(point1[0]==point2[0])
            {
                return point1[1]>point2[1] ; 
            }
            return point1[0]<point2[0] ; 
        } ; 

        int n = points.size() ; 
        sort(begin(points) , end(points) , lambda) ; 
        int count  = 0 ; 

        for(int i = 0 ; i<n ; i++)
        {
            //A:-
            int x1 = points[i][0] ; 
            int y1 = points[i][1] ; 

            //B:-
            int maxy = INT_MIN ; 
            for(int j = i+1 ; j<n ; j++)
            {
                int x2 = points[j][0] ; 
                int y2 = points[j][1] ; 

                if(y2>y1) continue ; 

                if(y2>maxy)
                {
                    count++;
                    maxy = y2 ; 
                }

                 
            }
        }

        return count ; 
        
    }
};