// Last updated: 10/5/2025, 8:49:47 AM
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i=0 , j =0 ;
        for(auto command:commands)
        {
            if(command == "DOWN")
            {
                i++;
            }
            else if(command == "UP")
            {
                i--;
            }
            else if(command == "RIGHT")
            {
                j++;
            }
            else if(command == "LEFT")
            {
                j--;
            }
        }
        return (i*n)+j;
        
    }
};