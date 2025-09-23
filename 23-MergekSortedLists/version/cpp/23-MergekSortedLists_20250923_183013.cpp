// Last updated: 9/23/2025, 6:30:13 PM
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

    ListNode* patitionAndMerge(int start , int end ,vector<ListNode*>& lists )
    {
        if(start>end)
        {
            return NULL ; 
        }
        if(start == end)
        {
            return lists[start] ; 
        }
        int mid = start+(end-start)/2 ; 
        ListNode* left = patitionAndMerge(start , mid , lists) ; 
         ListNode* right = patitionAndMerge(mid+1 , end , lists) ; 

         return mergeTwoList(left , right) ; 

    }
    
    ListNode* mergeTwoList(ListNode* l1 , ListNode* l2)
    {
        if(!l1)
        {
            return l2 ; 
        }
        if(!l2)
        {
            return l1 ; 
        }
        if(l1->val <= l2->val)
        {
            l1->next = mergeTwoList(l1->next , l2) ;
            return l1 ; 
        }
        else
        {
            l2->next = mergeTwoList(l1 , l2->next) ;
            return l2 ;  
        }
        return NULL ; 
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int k =  lists.size() ; 

        if(k==0)
        {
            return NULL ; 
        }
        return patitionAndMerge(0 , k-1 , lists) ; 

        
    }
};