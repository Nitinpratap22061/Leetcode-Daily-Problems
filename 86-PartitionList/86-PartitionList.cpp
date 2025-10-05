// Last updated: 10/5/2025, 9:01:48 AM
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* list1 = new ListNode(-1);
        ListNode* list2 = new ListNode(-1);
        ListNode* temp = head;
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;

        while (temp) {
            if (temp->val < x) {
                temp1->next = temp;
                temp1 = temp1->next;
            } else {
                temp2->next = temp;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        temp1->next = head2->next;
        // Make sure to set the next of the last node in the second list to nullptr
        temp2->next = nullptr;

        return head1->next;
    }
};
