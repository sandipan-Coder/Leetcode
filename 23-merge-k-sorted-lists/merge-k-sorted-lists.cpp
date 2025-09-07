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

    ListNode* mergeTwoList(ListNode* list1, ListNode* list2){

        if(!list1 && !list2)
            return NULL;
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        
        ListNode* dummyptr = new ListNode(-1);
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* curr = dummyptr;

        while(ptr1 && ptr2){

            if(ptr1->val < ptr2->val){
                curr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else{
                curr->next = ptr2;
                ptr2 = ptr2->next;
            }

            curr = curr->next;
        }

        if(ptr1)
            curr->next = ptr1;
        if(ptr2)
            curr->next = ptr2;

        return dummyptr->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0)
            return NULL;
        if(lists.size() == 1)
            return lists[0];

        while(lists.size() > 1){

            ListNode* merge = mergeTwoList(lists[0], lists[1]);
            lists.push_back(merge);
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }

        return lists[0];
    }
};