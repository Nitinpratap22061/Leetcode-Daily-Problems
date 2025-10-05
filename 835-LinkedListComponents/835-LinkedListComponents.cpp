// Last updated: 10/5/2025, 8:57:37 AM
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        ListNode* curr = head;
        int components = 0;

        while (curr) {
            if (numSet.count(curr->val) && (curr->next == nullptr || !numSet.count(curr->next->val))) {
                components++;
            }
            curr = curr->next;
        }

        return components;
    }
};
