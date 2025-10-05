// Last updated: 10/5/2025, 9:02:59 AM
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>ans(numRows);
        if(numRows == 1)
        {
            return s ; 
        }
        bool flag = false;
        int i = 0 ;
        for(auto ch : s)
        {
            ans[i]+=ch;
            if(i==0 || i==numRows-1)
            {
                flag = !flag;
            }
        
        if(flag)
        {

            i=i+1;
        }
        else
        {
            i-=1;
        } 
        } 
        string res;
        for(auto ele : ans)
        {
            res+=ele;
        }
        return res;
    }
};