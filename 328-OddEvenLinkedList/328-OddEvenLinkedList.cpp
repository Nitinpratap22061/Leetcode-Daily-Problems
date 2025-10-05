// Last updated: 10/5/2025, 8:59:37 AM
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* temp1 = head;              
        ListNode* temp2 = head->next;        
        ListNode* temp3 = temp2;            

        while (temp2 && temp2->next) {
            temp1->next = temp2->next;      
            temp1 = temp1->next;             

            temp2->next = temp1->next;       
            temp2 = temp2->next;           
        }

        temp1->next = temp3;                 
        return head;
    }
};
