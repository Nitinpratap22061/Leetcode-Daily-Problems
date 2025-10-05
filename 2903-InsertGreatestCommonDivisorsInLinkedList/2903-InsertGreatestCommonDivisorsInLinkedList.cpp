// Last updated: 10/5/2025, 8:51:08 AM

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        int value;
        ListNode* temp1= head;
        ListNode* temp2= temp1->next;
        while(temp1->next!=NULL){
            value=gcd(temp1->val,temp2->val);
            ListNode* header=new ListNode(value);
            temp1->next=header;
            header->next=temp2;
            temp1=temp2;
            temp2=temp2->next;

        }
        return head;   
    }
};