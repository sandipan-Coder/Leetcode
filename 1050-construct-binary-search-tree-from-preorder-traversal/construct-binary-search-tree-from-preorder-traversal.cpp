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

    TreeNode* helper(int &idx, vector<int>& preorder, int bound){

        if(idx == preorder.size() || preorder[idx] > bound)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[idx++]);

        root->left = helper(idx, preorder, root->val);
        root->right = helper(idx, preorder, bound);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int i = 0;
        return helper(i, preorder, INT_MAX);
    }
};