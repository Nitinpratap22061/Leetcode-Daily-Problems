// Last updated: 10/5/2025, 8:50:55 AM
class Solution {
public:
   bool isHD(int i , int j , vector<string>& words )
   {
     string word1 = words[i];
     string word2 = words[j];
     int count = 0;
     int n = word1.size();
     for(int i = 0 ; i<n ; i++)
     {
        if(word1[i]!=word2[i])
        {
            count++;
        }
     }
     if(count==1)
     {
        return true;
     }
     return false;
   }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
       
        int n = words.size() ; 
        vector<int>dp(n , 1);
        vector<int>parent(n , -1);
        int LIS = 1 ; 
        int longIdx=0;

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<=i-1 ; j++)
            {
                if(groups[i]!=groups[j] && words[i].length() == words[j].length() &&isHD(i,j,words))
                {
                    if(dp[j]+1 > dp[i] )
                    {
                        dp[i] = dp[j]+1;
                        parent[i] = j ; 
                        if(LIS<dp[i])
                        {
                            LIS = dp[i];
                            longIdx = i  ; 
                        }
                    }
                }


            }
        }

        vector<string>result;
        while(longIdx!=-1)
        {
            result.push_back(words[longIdx]);
            longIdx = parent[longIdx];
        }
        reverse(begin(result) , end(result));
        return result ; 
        
    }
};