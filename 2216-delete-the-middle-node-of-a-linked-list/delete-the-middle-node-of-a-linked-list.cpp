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
    ListNode* deleteMiddle(ListNode* head) {

        if(!head->next)
            return NULL;
        
        ListNode* first = head;
        ListNode* slow = head;
        ListNode* prev = NULL;

        while(first && first->next) {
            first = first->next->next;
            prev = slow;
            slow = slow->next;
        }

        prev->next = slow->next;
        slow->next = NULL;
        // free(slow);

        return head;
    }
};