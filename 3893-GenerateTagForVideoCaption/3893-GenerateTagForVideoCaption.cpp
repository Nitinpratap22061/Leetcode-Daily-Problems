// Last updated: 10/5/2025, 8:48:40 AM
class Solution {
public:
    string generateTag(string caption) {
        string tag = "#";
        bool newWord = true;
        int i = 0;

        while (i < caption.length()) {
            if (isalpha(caption[i])) {
                char ch = caption[i];
                if (newWord) {
                    if (tag.length() == 1) {
                        tag += tolower(ch);
                    } else {
                        tag += toupper(ch);
                    }
                    newWord = false;
                } else {
                    tag += tolower(ch);
                }
            } else if (caption[i] == ' ') {
                newWord = true;
            }
            i++;
        }

        if (tag.length() > 100) {
            tag = tag.substr(0, 100);
        }

        return tag;
    }
};
