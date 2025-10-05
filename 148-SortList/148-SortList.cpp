// Last updated: 10/5/2025, 9:00:51 AM
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
    ListNode* sortList(ListNode* head) {
        
        ListNode* temp1=head;
        ListNode* temp2=head;
        ListNode* header=new ListNode(100);
         ListNode* temp=header;
        multiset<int>s1;

        while(temp1!=NULL){
            s1.insert(temp1->val);
            temp1=temp1->next;
             }
             for(auto elements:s1){
             ListNode* header1=new ListNode(elements);
             temp->next=header1;
             temp=temp->next;
             }

        
        
        

     return header->next;
        
    }
};