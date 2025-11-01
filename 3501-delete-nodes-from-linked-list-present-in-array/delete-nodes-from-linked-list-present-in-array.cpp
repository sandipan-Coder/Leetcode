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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        bitset<100001> bit;
        for(int &num: nums)
            bit[num] = 1;
        
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr){

            if(bit[curr->val]){

                if(curr == head){
                    ListNode* next = curr->next;
                    curr->next = NULL;
                    curr = next;
                    head = curr;
                }
                else{
                    ListNode* next = curr->next;
                    prev->next = next;
                    curr->next = NULL;
                    curr = next;
                }

            } else {

                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};