// Last updated: 10/5/2025, 8:51:51 AM
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
    ListNode* removeNodes(ListNode* head) {


        stack<ListNode*>st ; 
        ListNode* curr = head ; 
        while(curr!=NULL)
        {
            st.push(curr) ; 
            curr = curr->next ; 
        }

          curr = st.top() ; 
          st.pop() ; 
          ListNode* newnode = new ListNode(curr->val) ; 
          int maxval = curr->val ; 

          while(!st.empty())
          {
            curr = st.top() ; 
            st.pop() ; 

            if(curr->val < maxval) continue ; 
            else
            {
                ListNode* temp = new ListNode(curr->val) ; 
                temp->next = newnode ; 
                newnode = temp ; 
                maxval = curr->val ; 
            }
          }

             return newnode;
          

        
    }
};