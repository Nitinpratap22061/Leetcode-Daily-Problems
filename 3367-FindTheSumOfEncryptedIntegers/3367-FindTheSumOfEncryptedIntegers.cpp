// Last updated: 10/5/2025, 8:50:18 AM
class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        { 
            string ans="";
            string help="";
            string counter="";
            int r=0;
            int result=0;
            int count=0;
            int number=nums[i];
            int maxi=INT_MIN;
            while(number>0)
            {
                count++;
                r=number%10;
                if(r>maxi)
                {
                    maxi=r;
                }
                number=number/10;
            }
            help=to_string(maxi);
            counter=to_string(count);
            while(count!=0)
            {
                ans=ans+help;
                count--;
            }
            result=stoi(ans);
            sum=sum+result;
        }
        return sum;
        
    }
};