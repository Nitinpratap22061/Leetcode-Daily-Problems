// Last updated: 10/5/2025, 8:48:03 AM
class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        set<pair<int,int>> st; 
        int i = 0, j = 0;
        map<char ,int>mp ; 
        for(auto &ch : s)
        {
            mp[ch]++ ; 
        }


        while (j < n) {
            mp[s[j]]--;
            if (j - i + 1 == k) {
                int x = 0, y = 0;        
                for(auto &ele : mp)
                {
                    if(ele.first =='U')
                    {
                        y+=ele.second ; 
                    }
                    else if(ele.first == 'D')
                    {
                        y-=ele.second; 
                    }
                    else if(ele.first == 'L')
                    {
                        x-=ele.second ; 
                    }
                    else
                    {
                        x+=ele.second ; 
                    }
                }
                st.insert({x,y});
                mp[s[i]]++ ; 
                i++;
            }
           
            j++;
        }

        return st.size();
    }
};
