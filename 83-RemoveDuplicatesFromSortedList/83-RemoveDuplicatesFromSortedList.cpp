// Last updated: 10/5/2025, 9:01:50 AM
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp1=head;
        ListNode* temp2;
        while(temp1!=NULL)
        {
            temp2=temp1->next;
            while(temp2!=NULL)
            {
                if(temp1->val==temp2->val)
                {
                    temp1->next=temp2->next;
                }
                temp2=temp2->next;

            }
            temp1=temp1->next;
        }
        return head;
        
    }
};