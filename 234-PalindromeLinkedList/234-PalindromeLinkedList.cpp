// Last updated: 10/5/2025, 9:00:09 AM
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
    bool isPalindrome(ListNode* head) {

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* current=slow->next;
        slow->next=NULL;
         while(current!=NULL){
             ListNode* nextptr=current->next;
             current->next=slow;
             slow=current;
             current=nextptr;
         }

         ListNode* head1=head;
         ListNode* head2=slow;

         while(head2){
             if(head1->val!=head2->val){
                 return false;
             }
             head1=head1->next;
             head2=head2->next;
         }

         return true;



        
    }
};