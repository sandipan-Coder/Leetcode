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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left == right)
            return head;
        
        ListNode* dummy = new ListNode(-501);
        dummy->next = head;
        ListNode* leftPrev = dummy;
        
        int left1 = left;
        left1--;

        // This traverse is for pointing previous node of left point.
        while(left1){
            leftPrev = leftPrev->next;
            left1--;
        }

        ListNode* temp = leftPrev->next;
        ListNode* curr = temp;
        ListNode* prev = NULL;

        for(int i = 0; i <= right - left; i++){

            ListNode* nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }

        leftPrev->next = prev;
        temp->next = curr;

        return dummy->next;
    }
};