// Last updated: 10/5/2025, 9:00:07 AM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {

        ListNode* temp = node ; 
        ListNode* prev = NULL ; 

        while(temp->next !=NULL)
        {
            swap(temp->val , temp->next->val) ; 
            prev = temp ; 
            temp=temp->next ; 
        }
        prev->next=NULL;
        
    }
};