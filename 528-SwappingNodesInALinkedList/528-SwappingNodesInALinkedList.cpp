// Last updated: 10/5/2025, 8:58:43 AM
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp1=head;
        ListNode* temp2=head;
        int n=0;
        ListNode* temp=head;

        while(temp!=NULL){
            temp=temp->next;
            n++;

        }
        if(head->next==NULL){
            return head;
        }
        else{
            for(int i=1;i<k;i++){
                temp1=temp1->next;
            }
             for(int i=1;i<n-k+1;i++){
                temp2=temp2->next;
            }
            swap(temp1->val,temp2->val);

        }
        return head;
        
    }
};