/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:

    int bfs(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        int curSum = 0;

        while(!q.empty()) {

            curSum = 0;
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                curSum += node->val;

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }

        return curSum;
    }

public:
    int deepestLeavesSum(TreeNode* root) {
        
        return bfs(root);
    }
};