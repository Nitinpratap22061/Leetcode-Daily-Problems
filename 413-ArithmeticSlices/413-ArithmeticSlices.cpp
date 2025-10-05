// Last updated: 10/5/2025, 8:59:12 AM
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int total = 0;  // Final answer store karega
    int count = 0;  // Consecutive arithmetic subarrays ka count rakhega

    // Index 2 se start kar rahe hain kyunki 3 elements ka difference dekhna hai
    for (int i = 2; i < nums.size(); i++) {
        // Check karo kya difference same hai
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            count++;       // Ek aur arithmetic slice mila
            total += count; // Iska count total mein add karo
        } else {
            count = 0;     // Pattern toot gaya, count reset
        }
    }

    return total;  // Total arithmetic subarrays return karo
        
    }
};