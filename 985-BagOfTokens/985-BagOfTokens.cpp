// Last updated: 10/5/2025, 8:56:57 AM
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxscore=0;
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();
        int i=0,j=n-1;
        int score=0;
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                power-=tokens[i];
                score++;
                i++;
                maxscore=max(maxscore,score);
            }
            else if(score>=1)
            {
                power+=tokens[j];
                score-=1;
                j--;
            }
            else
            {
                return maxscore;
            }
        }

        return maxscore;
    }
};