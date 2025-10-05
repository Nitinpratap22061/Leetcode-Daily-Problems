// Last updated: 10/5/2025, 8:55:53 AM
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st(begin(folder) , end(folder));
        vector<string>res;

        for(auto currfolder:folder)
        {
            string tempfolder = currfolder;
            bool issubfolder = false;
            while(!currfolder.empty())
            {
                auto pos = currfolder.find_last_of('/');
                currfolder = currfolder.substr(0,pos);
                if(st.find(currfolder)!=st.end())
                {
                    //subfolder ;
                    issubfolder = true;
                    break;
                }
            }
            if(!issubfolder)
            {
                   res.push_back(tempfolder);
            }
        }
        return res;
        
    }
};