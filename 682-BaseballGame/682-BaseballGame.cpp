// Last updated: 10/5/2025, 8:58:03 AM
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>ans;
        int help;
        int sum=0;
        string a = "+";
        string b = "C";
        string c = "D";
        for(auto ele:operations)
        {
            if(ele !=a && ele!=b && ele!=c)
            {
               help=stoi(ele);
               ans.push_back(help); 
            }
            else if(ele == a)
            {

                int help1 = (ans[ans.size()-1]);
                int help2 = (ans[ans.size()-2]);
                int answer = help1 + help2;

                ans.push_back(answer);

            }

            else if(ele==c)
            {
                int help1 = (ans[ans.size()-1]);
                int answer = help1 * 2;

                ans.push_back(answer);
            }
            else if(ele == b)
            {

                ans.pop_back();

            }

        }
        for(auto elements : ans)
        {
            sum+=elements;
        }
        return sum;
    }
};