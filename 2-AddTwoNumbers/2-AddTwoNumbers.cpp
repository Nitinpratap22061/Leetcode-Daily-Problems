// Last updated: 10/5/2025, 9:03:04 AM
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(100);
        ListNode* temp3=dummy;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        
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

        return dummy->next;


        
    }
};