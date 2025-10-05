// Last updated: 10/5/2025, 8:55:43 AM
class Solution {
public:

    unordered_set<int>foundbox;
    int solve(auto box , vector<bool>& visited , vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes)
    {
      if(visited[box])
      {
        return 0;
      } 
      if(status[box]==0)
      {
        foundbox.insert(box);
        return 0 ; 
      } 
      visited[box]=true;
      int candy = 0 ;
      candy+=candies[box];
      for(int &insidebox:containedBoxes[box])
      {
         candy+=solve(insidebox , visited , status , candies , keys , containedBoxes);
      }
      for(int &boxkey : keys[box])
      {
        status[boxkey]=1;
        if(foundbox.count(boxkey)!=0)
        {
            candy+=solve(boxkey , visited , status , candies , keys , containedBoxes);
        }
      }
      return candy;
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int candiess = 0 ;
        int n = status.size();
        vector<bool>visited(n,false);

        for(int &box : initialBoxes)
        {
            candiess+=solve(box,visited , status , candies , keys , containedBoxes);
        }
        return candiess ; 
        
    }
};