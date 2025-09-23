// Last updated: 9/23/2025, 5:18:57 PM
class Solution {
public:
    ListNode* find(ListNode* node, int k) {
        while (node && --k) {
            node = node->next;
        }
        return node;
    }

    ListNode* rev(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp) {
            ListNode* kthNode = find(temp, k);
            if (!kthNode) {
                if (prev) prev->next = temp;
                break;
            }

            ListNode* nextnode = kthNode->next;
            kthNode->next = nullptr;

            ListNode* newHead = rev(temp);

            if (temp == head) {
                head = newHead;
            } else {
                prev->next = newHead;
            }

            prev = temp;
            temp = nextnode;
        }

        return head;
    }
};
