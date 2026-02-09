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

    void inorderTraversal(TreeNode* root, vector<int> &arr) {

        if(!root)
            return;
        
        inorderTraversal(root->left, arr);
        arr.push_back(root->val);
        inorderTraversal(root->right, arr);
    }

    TreeNode* constructBST(int low, int high, vector<int> &arr) {

        if(low > high)
            return NULL;
        
        int mid = low + (high - low) / 2;
        TreeNode* node = new TreeNode(arr[mid]);

        node->left = constructBST(low, mid - 1, arr);
        node->right = constructBST(mid + 1, high, arr);

        return node;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        
        // Step 1 :- Inorder Traversal of the given Tree.
        vector<int> arr;
        inorderTraversal(root, arr);


        // Step 2 :- Construct the Balance BST.
        int n = arr.size();
        return constructBST(0, n-1, arr);
    }
};