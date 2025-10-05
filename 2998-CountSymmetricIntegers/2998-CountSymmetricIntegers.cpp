// Last updated: 10/5/2025, 8:51:06 AM
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i = low ; i<=high ; i++)
        {
            string num = to_string(i) ; 
            if(num.length()%2!=0) continue ; 
            else
            {
                int sum1 = 0 ;
                int sum2 = 0 ;
                for(int j = 0 ; j<num.length()/2 ; j++)
                {
                     sum1 +=num[j] - '0' ;
                }
                for(int j = num.length()/2 ; j<num.length() ; j++)
                {
                     sum2 += num[j] - '0';
                }
                if(sum1 == sum2)
                {
                    count++;
                }

            }


        }
        return count;
        
    }
};