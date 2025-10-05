// Last updated: 10/5/2025, 8:53:58 AM
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> degree;
        
        // Count degrees of each vertex
        for (const auto& edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        int center = -1;
        int maxDegree = 0;
        
        // Find the vertex with maximum degree
        for (const auto& [vertex, deg] : degree) {
            if (deg > maxDegree) {
                maxDegree = deg;
                center = vertex;
            }
        }
        
        return center;
    }
};
