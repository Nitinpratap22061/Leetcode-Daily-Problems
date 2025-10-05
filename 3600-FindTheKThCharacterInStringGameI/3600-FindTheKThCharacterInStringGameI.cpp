// Last updated: 10/5/2025, 8:49:42 AM
class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        int n = 1;

        while (word.size() < k) {
            int currentSize = word.size(); 

            for (int i = 0; i < currentSize; i++) { 
                char help = word[i];
                char next = (help == 'z') ? 'a' : help + 1; 
                word += next;

                if (word.size() >= k) break; 
            }
        }

        return word[k - 1];
    }
};
