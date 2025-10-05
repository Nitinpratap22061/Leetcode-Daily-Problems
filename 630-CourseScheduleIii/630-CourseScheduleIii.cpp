// Last updated: 10/5/2025, 8:58:19 AM
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // s1 sort courses based on lastday
        sort(courses.begin(), courses.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        priority_queue<int> maxHeap;
        int time = 0;
        for (auto& course : courses) {
            time += course[0];
            maxHeap.push(course[0]);

            if (time > course[1]) {
                time -= maxHeap.top();
                maxHeap.pop();
            }
        }

        return maxHeap.size();
    }
};