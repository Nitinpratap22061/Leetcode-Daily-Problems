// Last updated: 10/5/2025, 8:58:59 AM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

ListNode* reverseList(ListNode* head) {

        ListNode* current=head;
        ListNode* prev=NULL;
        while(current!=NULL){
            ListNode* nextptr=current->next;
            current->next=prev;
            prev=current;
            current=nextptr;
        }
        return prev;

        
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* head2=reverseList(l1);
         ListNode* head3= reverseList(l2);

        ListNode* dummy=new ListNode(100);
        ListNode* temp3=dummy;
        ListNode* temp1=head2;
        ListNode* temp2=head3;
        
        int carry=0;
        while(temp1&&temp2){
            int value=temp1->val+temp2->val+carry;
            temp3->next= new ListNode(value%10);
            carry=value/10;
            temp1=temp1->next;
            temp2=temp2->next;
            temp3=temp3->next;
        }

        while(temp1){

            int value=temp1->val+carry;
            carry=value/10;
            temp3->next= new ListNode(value%10);
            temp1=temp1->next;
            // temp2=temp2->next;
            temp3=temp3->next;

        }

        while(temp2){
            int value=temp2->val+carry;
            carry=value/10;
            temp3->next= new ListNode(value%10);
            // temp1=temp1->next;
            temp2=temp2->next;
            temp3=temp3->next;
        }
        if(carry){
            temp3->next=new ListNode(carry);
        }

         ListNode* head= reverseList(dummy->next);
         return head;
         
       
        
    }
};