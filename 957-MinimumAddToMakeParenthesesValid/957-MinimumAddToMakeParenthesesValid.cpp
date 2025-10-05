// Last updated: 10/5/2025, 8:57:06 AM
class Solution {
public:
       stack<char>st;  
       int count=0;   
    int minAddToMakeValid(string s) {
        for(int i=0 ; i<s.size() ;i++)
        {
            char ch=s[i];
            if(ch=='(')
            {
                st.push(ch);
            }
            else if(ch==')')
            {
                if(!st.empty())
                {
                    st.pop();
                }
                else
                {
                    count++;
                }
            }
        }
        int res = st.size();
        return res+count;

    }
};