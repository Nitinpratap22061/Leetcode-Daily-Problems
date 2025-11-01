// Last updated: 11/1/2025, 5:53:43 PM
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
