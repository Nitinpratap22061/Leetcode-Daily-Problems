// Last updated: 10/5/2025, 8:54:09 AM
class Solution {
public:
    int maximumScore(int a, int b, int c) {
              priority_queue<int>pq ; 
              pq.push(a);
              pq.push(b);
              pq.push(c);


              int score = 0  ; 
              int num1 = pq.top();
              pq.pop();
              int num2 = pq.top();
              pq.pop();
              while(num1!=0 && num2!=0)
              {
                score++ ; 
                num1--;
                num2--;
                pq.push(num1);
                pq.push(num2);
                 num1 = pq.top();
              pq.pop();
             num2 = pq.top();
              pq.pop();

              }
              return score;

    }
};
