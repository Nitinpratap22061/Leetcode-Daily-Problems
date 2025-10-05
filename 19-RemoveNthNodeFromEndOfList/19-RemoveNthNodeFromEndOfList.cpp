// Last updated: 10/5/2025, 9:02:46 AM
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp1=head;
        ListNode* temp2=head;
        ListNode* temp3=head;

        if(head->next==NULL){
            return NULL;
        }


        int count=0;
        while(temp1!=NULL){
            temp1=temp1->next;
            count++;
        }
        if(count-n==0){
                temp3=temp3->next;
            head=temp3;
        }
        for(int i=1;i<count-n;i++){
            temp2=temp2->next;

        }
        temp2->next=temp2->next->next;
        
        
        return head;
        
    }
};