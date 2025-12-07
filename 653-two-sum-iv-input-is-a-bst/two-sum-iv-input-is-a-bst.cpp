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

    void inorderTraversal(TreeNode* root, vector<int> &values){

        if(root == NULL)
            return;
        
        inorderTraversal(root->left, values);
        values.push_back(root->val);
        inorderTraversal(root->right, values);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> values;
        inorderTraversal(root, values);

        int i = 0;
        int j = values.size() - 1;

        while(i < j){

            if(values[i] + values[j] == k)
                return true;
            else if(values[i] + values[j] > k)
                j--;
            else
                i++;
        }

        return false;
    }
};