// Last updated: 11/27/2025, 5:19:20 PM
1class Solution {
2public:
3    string largestNumber(vector<int>& nums) {
4        // Convert integers to strings
5        vector<string> array;
6        for (int num : nums) {
7            array.push_back(to_string(num));
8        }
9
10        // Custom comparator for sorting
11        sort(array.begin(), array.end(), [](const string &a, const string &b) {
12            return (b + a) < (a + b);
13        });
14
15        // Handle the case where the largest number is "0"
16        if (array[0] == "0") {
17            return "0";
18        }
19
20        // Build the largest number from the sorted array
21        string largest;
22        for (const string &num : array) {
23            largest += num;
24        }
25
26        return largest;
27    }
28};