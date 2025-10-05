// Last updated: 10/5/2025, 9:02:41 AM
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
    ListNode* swapPairs(ListNode* head) {
        if( !head || !head->next){
            return head;
        }
            

        ListNode* dummyNode=new ListNode(100);
        ListNode* prev=dummyNode;
        ListNode* current=head;
        while(current && current->next){
            prev->next=current->next;
            current->next=prev->next->next;
            prev->next->next=current;
            prev=current;
            current=current->next;
        }
        return dummyNode->next;
        
    }
};