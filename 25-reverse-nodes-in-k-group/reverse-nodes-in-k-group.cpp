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

    void reverseLL(ListNode* head){

        ListNode* prev_ptr = NULL;
        ListNode* curr_ptr = head;

        while(curr_ptr){

            ListNode* next_ptr = curr_ptr->next;
            curr_ptr->next = prev_ptr;
            prev_ptr = curr_ptr;
            curr_ptr = next_ptr;
        }

        return;
    }

    ListNode* getKthNode(ListNode* temp, int k){

        k--;

        while(temp && k){
            k--;
            temp = temp->next;
        }

        return temp;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* prev_ptr = NULL;
        ListNode* curr_ptr = head;

        while(curr_ptr){

            ListNode* kthnode = getKthNode(curr_ptr, k);

            if(kthnode == NULL){
                
                if(prev_ptr){
                    prev_ptr->next = curr_ptr;
                    break;
                }
                else
                    return head;
            }

            ListNode* next_ptr = kthnode->next;
            kthnode->next = NULL;
            reverseLL(curr_ptr);

            if(curr_ptr == head)
                head = kthnode;
            else
                prev_ptr->next = kthnode;

            prev_ptr = curr_ptr;
            curr_ptr = next_ptr;
        }

        return head;
    }
};