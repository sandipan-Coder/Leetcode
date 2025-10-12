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

    int solve(TreeNode* root, int &moves){
        
        if(root == NULL)
            return 0;
        
        int left = solve(root->left, moves);
        int right = solve(root->right, moves);
        
        moves += (abs(left) + abs(right));
        
        return (left + right + root->val) - 1;
    }

public:
    int distributeCoins(TreeNode* root) {
        
        int moves = 0;
        solve(root, moves);
        
        return moves;
    }
};