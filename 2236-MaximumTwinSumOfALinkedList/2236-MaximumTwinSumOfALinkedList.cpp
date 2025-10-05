// Last updated: 10/5/2025, 8:53:05 AM
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
    int pairSum(ListNode* head) {

        vector<int>arr ; 
        ListNode* temp = head ; 
        while(temp!=NULL)
        {
            arr.push_back(temp->val) ; 
            temp = temp->next ; 
        }
        int n = arr.size() ; 
        int i = 0 ; 
        int j = n-1 ; 

int maxsum = 0 ;
        while(i<j)
        {
               maxsum = max(maxsum , (arr[i]+arr[j])) ; 
               i++;
               j--;
        }

        return maxsum ; 
        
    }
};