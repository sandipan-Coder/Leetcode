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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* temp = head;
        int total = 1;

        while(temp -> next != NULL){
            total++;
            temp = temp->next;
        }

        if(k > total)
            return head;
        
        if(k == 1 || k == total){
            swap(head->val, temp->val);
            return head;
        }

        temp = head;
        ListNode* first = NULL;
        ListNode* last = NULL;
        int count = 0;

        while(first == NULL || last == NULL){

            if(count == k-1)
                first = temp;
            if(total - count == k)
                last = temp;
            
            temp = temp->next;
            count++;
        }

        swap(first->val, last->val);
        
        return head;
    }
};