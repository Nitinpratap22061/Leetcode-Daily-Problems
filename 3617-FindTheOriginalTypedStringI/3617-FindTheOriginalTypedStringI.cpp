// Last updated: 10/5/2025, 8:49:39 AM
class Solution {
public:
    int possibleStringCount(string word) {
        int size = word.length();
        int count =1;
         for(int i = 1 ;  i<size ; i++)
         {
            if(word[i]==word[i-1])
            {
                count++;
            }
         }
         return count ; 
    }
};