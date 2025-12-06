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

    TreeNode* findRightMost(TreeNode* node){

        if(!node->right)
            return node;
        
        return findRightMost(node -> right);
    }

    TreeNode* helper(TreeNode* root){

        if(!root->left)
            return root->right;
        else if(!root->right)
            return root->left;
        
        TreeNode* RightMostNodeOfLeft = findRightMost(root->left);
        RightMostNodeOfLeft -> right = root->right;

        return root->left;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL)
            return NULL;
        
        if(root->val == key)
            return helper(root);
        
        TreeNode* ptr = root;
        while(ptr){

            if(ptr->val > key){
                if(ptr->left && ptr -> left -> val == key){
                    ptr -> left = helper(ptr->left);
                    break;
                }
                else
                    ptr = ptr->left;
            }
            else {

                if(ptr->right && ptr->right->val == key){
                    ptr -> right = helper(ptr->right);
                    break;
                }
                else
                    ptr = ptr -> right;
            }
        }

        return root;
    }
};