// Last updated: 10/5/2025, 8:53:31 AM
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
          int count =0 ;
        for(auto pattern: patterns )
        {
            if(word.find(pattern)!=string::npos)
            {
                count++;
            }
        }
        return count;
        
    }
};