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

    int findDiameter(TreeNode* root, int &dia){
        
        if(root == NULL)
            return 0;
        
        int leftHeight = findDiameter(root->left, dia);
        int rightHeight = findDiameter(root->right, dia);
        dia = max(dia, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int diameter = 0;
        findDiameter(root, diameter);

        return diameter;
    }
};