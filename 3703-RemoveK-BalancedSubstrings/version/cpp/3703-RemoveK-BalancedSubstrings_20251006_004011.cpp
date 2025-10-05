// Last updated: 10/6/2025, 12:40:11 AM
class Solution {
public:
    string removeSubstring(string s, int k) {
        //code 
         vector<int>cnts ; 
         char prev = '.' ; 
         for(auto x:s)
         {
            if(x==prev) cnts.back()++;
            else cnts.push_back(1) ; 
            prev = x ; 
         }
         stack<pair<int,int>>st ; 
         int type = ((s[0]=='(')?1:-1) ; 
         for(auto x: cnts)
         {
            st.push({type,x}) ; 
            type*=-1 ; 

            while(st.size()>=2)
            {
                auto ele1 = st.top() ; 
                st.pop() ; 
                 auto ele2 = st.top() ; 
                 st.pop() ; 
                 int at = ele1.first ; 
                 int av= ele1.second ; 
                 int bt = ele2.first ; 
                 int bv = ele2.second ; 

                 if(at == bt){
                    st.push({at,av+bv}) ; 
                    continue ; 
                 }
                 if(at!=-1)
                 {
                    st.push({bt,bv}) ; 
                    st.push({at,av}) ; 
                    break ; 
                 }
                 int v= min(av,bv)/k ; 
                 av -=k*v ; 
                 bv -=k*v ; 
                 if(bv) st.push({bt,bv}) ; 
                 if(av) st.push({at,av}) ; 
                 if(v == 0 ) break ; 
                
            }
         }

         string ans = "" ; 
         while(!st.empty())
         {
            auto[type , x] = st.top() ; 
            st.pop() ; 
            while(x--)
            {
                ans.push_back((type==1)?'(':')') ; 

            }
         }
         reverse(ans.begin() , ans.end()) ; 
         return ans ; 
    }
};