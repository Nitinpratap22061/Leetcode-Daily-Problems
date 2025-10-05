// Last updated: 10/5/2025, 8:54:20 AM
class Solution {
public:
    string solve1(string& s1 , string& s2)
    {
        stack<char>st ; 
        for(char &ch : s1)
        {
            if(ch==s2[1] && !st.empty() && st.top()==s2[0])
            {
                st.pop();
            }
            else
            {
                st.push(ch) ; 
            }
        }

        string temp ; 
        while(!st.empty())
        {
            temp.push_back(st.top());
            st.pop() ; 
        }
        reverse(temp.begin() , temp.end());

        return temp;
    }
    int maximumGain(string s, int x, int y) {

        int n = s.length() ; 
        int score = 0 ; 
        string maxi = (x>=y)?"ab":"ba" ; 
        string mini = (x<y)?"ab":"ba" ; 

        //first pass 
        string temp1 = solve1(s,maxi) ; 
        int L = temp1.length() ; 

        int removed = n-L ; 

        score+=(removed/2)*(max(x,y)) ; 

        //second pass 
        string temp2 = solve1(temp1,mini) ;
        int len = temp2.length() ;
        int remove = L-len ; 
        score+=(remove/2)*min(x,y);


        return score ;

        
    }
};