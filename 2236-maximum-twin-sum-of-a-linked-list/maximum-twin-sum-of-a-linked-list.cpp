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
private:

    ListNode* reverseLL(ListNode* head){

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr) {
            
            ListNode* nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }

        return prev;
    }

public:
    int pairSum(ListNode* head) {
        
        ListNode* first = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        int ans = INT_MIN;

        while(first && first->next){
            first = first->next->next;
            prev = slow;
            slow = slow->next;
        }

        prev->next = NULL;
        slow = reverseLL(slow);
        prev = head;

        while(prev){

            int sum = (prev->val + slow->val);
            prev = prev->next;
            slow = slow->next;

            ans = max(ans, sum);
        }

        return ans;
    }
};