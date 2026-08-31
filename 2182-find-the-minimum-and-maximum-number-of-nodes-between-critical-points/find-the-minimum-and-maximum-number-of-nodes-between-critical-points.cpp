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

    bool isCP(ListNode* curr, ListNode* prev){
        if(prev->val > curr->val && curr->next->val > curr->val)
            return true;   // Local Minimum
        if(prev->val < curr->val && curr->next->val < curr->val)
            return true;  // Local Maximum
        return false;
    }

public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        vector<int>ans(2, INT_MAX);
        if(!curr->next)
            return {-1, -1};
        int firstcp = -1, lastcp = -1, currpos = 0;
        while(curr->next){
            if(isCP(curr,prev)){
                if(firstcp == -1){
                    firstcp = currpos;
                    lastcp = currpos;
                }else{
                    ans[0] = min(ans[0], currpos - lastcp);
                    ans[1] = currpos - firstcp;
                    lastcp = currpos;
                }
            }
            currpos++;
            prev = curr;
            curr = curr->next;
        }
        if(ans[0] == INT_MAX)
            return {-1, -1};
        return ans;
    }
};