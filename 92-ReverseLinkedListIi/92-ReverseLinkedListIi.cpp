// Last updated: 10/5/2025, 9:01:42 AM
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* agla;
        ListNode* temp;

        for (int i = 1; i <= right - left; i++) {
            agla = curr->next;
            temp = agla->next;

            agla->next = prev->next;
            prev->next = agla;          
            curr->next = temp;
        }

        return dummy->next;
    }
};
