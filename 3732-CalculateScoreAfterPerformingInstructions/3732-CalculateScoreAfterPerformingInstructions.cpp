// Last updated: 10/5/2025, 8:49:16 AM
class Solution {
public:
     int n ;
     long long score = 0 ;
    void solve(vector<string>& instructions, vector<int>& values , int i , unordered_set<long long>& st)
    {
        if(i<0||i>=n || st.find(i)!=st.end())
        {
            return;
        }
        
        if(instructions[i]=="jump")
        {
            st.insert(i);
            solve(instructions , values , i+values[i] , st);
        }
        else if(instructions[i]=="add")
        {
            st.insert(i);
            score+=values[i];
            solve(instructions , values , i+1 , st);
        }
        return ;

    }
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        n = instructions.size();
        unordered_set<long long>st;
        solve(instructions , values , 0 ,st);
        return score;
        
    }
};