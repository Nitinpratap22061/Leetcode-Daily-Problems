// Last updated: 10/5/2025, 9:02:16 AM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();//row
        int n=matrix[0].size(); // column ;
        int dir=0;
        int top=0;
        int down=m-1;
        int left=0;
        int right=n-1;
        vector<int>res;
        while(top<=down && left<=right)
        {
            if(dir==0)
            {
                for(int i=left;i<=right;i++)
                {
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            if(dir==1)
            {
                for(int i=top;i<=down;i++)
                {
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            if(dir==2)
            {
                for(int i=right;i>=left;i--)
                {
                   res.push_back(matrix[down][i]);
                }
                down--;
            }
            if(dir==3)
            {
                for(int i=down;i>=top;i--)
                {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
            if(dir==4)
            {
                dir=0;
            }
        }
        return res;
        
    }
};