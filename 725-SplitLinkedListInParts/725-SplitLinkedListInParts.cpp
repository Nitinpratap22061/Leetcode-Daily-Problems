// Last updated: 10/5/2025, 8:57:56 AM
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* current=root;
        ListNode* prev=NULL;
        ListNode* temp=root;
        
        vector<ListNode*> parts(k, nullptr);
        int count=0;
         while(temp){
             count++;
             temp=temp->next;
         }
         int extranode=count%k;

        int nodetofill=count/k;
        for(int i=0;i<k;i++){
              parts[i]=current;
              for(int i=1;i<=count/k+(extranode>0?1:0);i++){
                  prev=current;
                  if(current!=NULL){
                  current=current->next;
                  }
              }
              if(prev!=NULL){
              prev->next=NULL;
              }
              extranode--;
        }
        return parts;
    }
       
};