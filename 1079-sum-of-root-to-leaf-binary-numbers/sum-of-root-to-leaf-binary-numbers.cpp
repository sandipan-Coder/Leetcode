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

    int dfs(TreeNode* node, int curr) {

        if (!node) 
            return 0;

        curr = (curr * 2) + node->val; // append this bit

        if (!node->left && !node->right) // leaf
            return curr;

        return dfs(node->left, curr) + dfs(node->right, curr);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        
        if(!root->left && !root->right)
            return root->val;
        
        return dfs(root, 0);
    }
};