// Last updated: 10/5/2025, 8:54:33 AM
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>> pq;
         int i = 0 ; 
        for (; i < heights.size()-1; i++) {
            if (heights[i + 1] <= heights[i])
                continue;
            else {
                int diff = heights[i + 1] - heights[i];
                if (bricks >= diff) {
                    // usse them first ;
                    bricks -= diff;
                    pq.push(diff);

                } else if (ladders != 0) {
                    // regert hai ??
                    if (!pq.empty()) {
                        int maxbrickusepast = pq.top();
                        if (maxbrickusepast > diff) {
                            // jarurat puri
                            bricks += maxbrickusepast;
                            pq.pop();
                            bricks -= diff;
                            pq.push(diff);
                            ladders--;
                        } else {
                            ladders--;
                        }

                    } else {
                        ladders--;
                    }

                } else {
                    break;
                }
            }
        }
        return i;
    }
};