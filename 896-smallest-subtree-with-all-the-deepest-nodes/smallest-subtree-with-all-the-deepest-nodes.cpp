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
    #define pairNodeInt pair<TreeNode*, int>
private:
    pairNodeInt findLCA(TreeNode* curr){
        
        if(!curr)
            return {nullptr, 0};
        
        pairNodeInt left = findLCA(curr->left);
        pairNodeInt right = findLCA(curr->right);

        if(left.second == right.second)
            return {curr, 1 + left.second};
        else if(left.second > right.second)
            return {left.first, 1 + left.second};
        else
            return {right.first, 1 + right.second};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        pairNodeInt res = findLCA(root);
        return res.first;
    }
};