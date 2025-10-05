// Last updated: 10/5/2025, 8:52:21 AM
class Solution {
public:

  long long nC2(int n) {
    return 1LL * n * (n - 1) / 2;
}

    long long zeroFilledSubarray(vector<int>& nums) {

        // no of 0 --- 4
        // 4 subarray 
        // contiguos 3 --- > subarray --- > 3 ; 
        // 3+5+1 = 9 

        // 0000 = 00 / 00 / 00/ 000 / 000 / 0000 /   4---6 
        // 000 = 00/00/000 3---->3 val of 4c2 = 4 fact /
        // 00000= 00---4 ,000-3 , 0000--2 , 00000 -1 = 10 5c2  



        
        int count = 0 ; 

        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(nums[i]==0)
            {
                count++ ; 
            }
        }
        vector<int>helper ; 
        int countinuos = 0 ; 
        for(int i = 1 ; i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                countinuos++;
            }
            else
            {
                if(countinuos>0)
                {
                    helper.push_back(countinuos+1) ; 
                    countinuos = 0 ;
                }

                 
            }
        }
        if(countinuos>0)
        {
             helper.push_back(countinuos+1) ; 
        }
   long long res = count ; 

        for(auto ele : helper)
        {
            res+=nC2(ele) ;
            cout<<ele<<endl; 

        }
        
        return res ; 
        
    }
};