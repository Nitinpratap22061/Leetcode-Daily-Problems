// Last updated: 10/5/2025, 8:57:15 AM
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size() ; 
        int boats = 0 ; 
        sort(begin(people) , end(people)) ; 
        int i = 0 ;
        int j = n-1 ; 
        while(i<=j)
        {
            if(people[j] + people[i] <= limit)
            {
                i++;
                j--;
                boats = boats+1;
            }
            else
            {
                j--;
                boats = boats+1;
            }
        }
        return boats;
        
    }
};