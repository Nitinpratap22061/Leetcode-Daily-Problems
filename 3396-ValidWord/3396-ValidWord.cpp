// Last updated: 10/5/2025, 8:50:13 AM
class Solution {
public:
    bool isValid(string word) {
       
        if (word.length() < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char ch : word) {
           
            if (!isalnum(ch)) return false;

           
            if (isalpha(ch)) {
               
                char lower = tolower(ch);

               
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }

        
       if(hasVowel && hasConsonant)
       {
        return true;
       }
       return false; 
    }
};
