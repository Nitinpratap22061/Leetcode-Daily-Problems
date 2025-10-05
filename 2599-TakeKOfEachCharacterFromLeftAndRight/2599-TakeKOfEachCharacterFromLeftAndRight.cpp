// Last updated: 10/5/2025, 8:51:46 AM
class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        int count_a = 0 ;
        int count_b = 0 ; 
        int count_c = 0 ;
        int i = 0 ;
        int j = 0 ;
        int maxnotdeletedwindow=0;
        for(auto &ch:s)
        {
            if(ch=='a')
            {
                count_a++;
            }
            else if(ch=='b')
            {
                count_b++;
            }
            else if(ch=='c')
            {
                count_c++;
            }
        }

        if(count_a<k || count_b<k || count_c<k)
        {
            return -1;
        }
        while(j<n)
        {
            if(s[j]=='a')
            {
                count_a--;
            }
            else if(s[j]=='b')
            {
                count_b--;
            }
            else if(s[j]=='c')
            {
                count_c--;
            }
            while(i<=j && count_a<k || count_b<k || count_c<k)
            {
                //shrink
                if(s[i]=='a')
                {
                    count_a++;
                }
                else if(s[i]=='b')
                {
                    count_b++;
                }
                else if(s[i]=='c')
                {
                    count_c++;
                }
                i++;
            }
            maxnotdeletedwindow = max(maxnotdeletedwindow , j-i+1);
            j++;

        }
        int res = n-maxnotdeletedwindow;
        return res;

        
    }
};