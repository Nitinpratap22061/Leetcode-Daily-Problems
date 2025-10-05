// Last updated: 10/5/2025, 9:02:11 AM
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        int n=0;
        if(head==NULL || k==0)
        {
            return head;
        }
        while(temp->next)
        {
            temp=temp->next;  //last element p pointer temp
            n++;
        }
        k=k%(n+1);
        temp->next=head;
        int jump=n-k;
        temp=head;
        while(jump)
        {
            temp=temp->next;
            jump--;
        }
        ListNode* returnhead=temp->next;
        temp->next=NULL;

        return returnhead;
        
    }
};