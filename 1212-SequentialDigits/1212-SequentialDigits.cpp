// Last updated: 10/5/2025, 8:56:18 AM
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>possibleans={12,23,34,45,56,67,78,89,123,234,345,456,567,678,789,1234,2345,3456,4567,5678,6789,12345,23456,34567,45678,56789,123456,234567,345678,456789,1234567,2345678,3456789,12345678,23456789,123456789};
        vector<int>res;
        int n=possibleans.size();
        for(int i=0;i<n;i++)
        {
            if(possibleans[i]<low)
            {
                continue;
            }
            if(possibleans[i]>high)
            {
                break;
            }
            res.push_back(possibleans[i]);
        }
        return res;
    }
};