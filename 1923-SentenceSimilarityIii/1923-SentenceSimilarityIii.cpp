// Last updated: 10/5/2025, 8:53:56 AM
#include <sstream>
#include <vector>

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        std::vector<std::string> words1, words2;

        // Split s1 and s2 into words
        std::istringstream stream1(s1), stream2(s2);
        std::string word;

        while (stream1 >> word) {
            words1.push_back(word);
        }
        while (stream2 >> word) {
            words2.push_back(word);
        }

        int n1 = words1.size(), n2 = words2.size();
        int i = 0, j = 0;

        // Check matching prefix
        while (i < n1 && i < n2 && words1[i] == words2[i]) {
            i++;
        }

        // Check matching suffix
        while (j < n1 - i && j < n2 - i && words1[n1 - 1 - j] == words2[n2 - 1 - j]) {
            j++;
        }

        // If the sum of matched prefix and suffix words covers at least one of the sentences, they are similar
        return i + j >= std::min(n1, n2);
    }
};
