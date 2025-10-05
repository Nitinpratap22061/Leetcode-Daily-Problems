// Last updated: 10/5/2025, 8:54:32 AM
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list1;
        ListNode* temp3 = list2;
        
        for (int i = 0; i < a - 1; i++) {
            temp1 = temp1->next;
        }
        
        for (int i = 0; i <= b; i++) {
            temp2 = temp2->next;
        }
        
        temp1->next = list2;
        while (temp3->next != NULL) {
            temp3 = temp3->next;
        }
        temp3->next = temp2;
        
        return list1;
    }
};
