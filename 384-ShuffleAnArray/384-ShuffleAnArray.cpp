// Last updated: 10/5/2025, 8:59:21 AM
class Solution {
    vector<int>original;
    int n;
public:
    Solution(vector<int>& nums) {
        original = nums;
        n = original.size();
        
    }
    
    vector<int> reset() {
        return original;
        
    }
    
    vector<int> shuffle() {
        //make a copy of original
        vector<int> shuffled = original;
        int shuffleSize = n;
        for(int i=n-1;i>=0;i--)
        {
            int j=rand()%shuffleSize;
            swap(shuffled[i],shuffled[j]);
            shuffleSize--;
        }
        return shuffled;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */