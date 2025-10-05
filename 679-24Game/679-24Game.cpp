// Last updated: 10/5/2025, 8:58:04 AM
class Solution {
public:
   int n ; 
   double epsilon = 0.1 ; 
   bool solve( vector<double>&cards) 
   {
       if(cards.size() ==1)
       {
        return abs(cards[0] - 24) <= epsilon ; 
       }
       //pick 2 poss no 
     for(int i = 0 ; i<cards.size() ; i++)
     {
        for(int j = 0 ; j<cards.size() ; j++)
        {
            if(i==j) continue ; 

            vector<double>temp ; 
            for(int k = 0 ; k<cards.size() ; k++)
            {
                if(k!=i && k!=j)
                {
                    temp.push_back(cards[k]) ; 
                }
            }

            double a = cards[i] ; 
            double b = cards[j] ; 

            vector<double>possval = {a+b , a-b , b-a , a*b };
            if(abs(b)>0.0)
            {
                possval.push_back(a/b) ; 
            }

             if(abs(a)>0.0)
            {
                possval.push_back(b/a) ; 
            }

            for(double val :possval)
            {
                temp.push_back(val) ;  // do 
                if(solve(temp) == true) return true ; //explore 
                temp.pop_back() ; // undo backtrack 
            }



        }

     }

     return false ;
   }
    bool judgePoint24(vector<int>& cards) {

        vector<double> nums ; // since value bhejenge point wala bhi 

        for(int i = 0 ; i<cards.size() ; i++)
         {
            nums.push_back(1.0*cards[i]) ; 
         }
        

     return solve(nums) ; 

        
    }
};




