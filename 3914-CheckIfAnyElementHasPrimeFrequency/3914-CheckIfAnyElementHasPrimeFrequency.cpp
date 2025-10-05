// Last updated: 10/5/2025, 8:48:38 AM
class Solution {
public:
    bool isPrime(int num)
    {
        int count = 0 ;
        for(int i=2 ; i<num ; i++)
            {
                if(num%i==0)
                {
                    count++;
                }
            }
        return count == 0;

    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i = 0 ; i<nums.size() ; i++)
            {
                mp[nums[i]]++; 
            }
        for(auto ele : mp)
            {
                int freq = ele.second;
                if(isPrime(freq) && freq>1)
                {
                    return true ; 
                }
            }
        return false ; 
        
    }
};