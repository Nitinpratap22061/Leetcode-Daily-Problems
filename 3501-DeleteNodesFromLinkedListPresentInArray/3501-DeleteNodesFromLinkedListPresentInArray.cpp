// Last updated: 10/5/2025, 8:49:55 AM
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_set<int> st; 
        for (auto ele : nums) {
            st.insert(ele); 
        } 

        ListNode* temp = head; 
        ListNode* prev = nullptr;
        ListNode* newHead = nullptr;

        while (temp != NULL) {
            if (st.find(temp->val) != st.end()) {
                temp = temp->next;
                continue; 
            } else {
                ListNode* newnode = new ListNode(temp->val); 
                if (prev == nullptr) {
                    newHead = newnode;
                    prev = newnode;
                } else {
                    prev->next = newnode;
                    prev = newnode;
                }
            }
            temp = temp->next;
        }

        return newHead;
    }
};
