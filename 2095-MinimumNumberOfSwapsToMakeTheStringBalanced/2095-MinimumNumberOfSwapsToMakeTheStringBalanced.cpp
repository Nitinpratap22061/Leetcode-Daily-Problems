// Last updated: 10/5/2025, 8:53:34 AM
class Solution {
public:
int count=0;
    int minSwaps(string s) {
        for(int i=0 ; i<s.size() ; i++)
        {
            char ch=s[i];
            if(ch=='[')
            {
                count++;
            }
            else if(count>0)
            {
                count--;
            }
        }
        return (count+1)/2;
        
    }
};