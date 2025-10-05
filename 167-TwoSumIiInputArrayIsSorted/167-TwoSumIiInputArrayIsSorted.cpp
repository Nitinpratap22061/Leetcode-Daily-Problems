// Last updated: 10/5/2025, 9:00:45 AM
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size() ;
        vector<int>ans;
        int i = 0 ;
        int j = n-1 ;
        while(i<=j)
        {
            int sum = numbers[i] + numbers[j] ;
            if(sum == target)
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if(sum>target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return ans;


        
    }
};