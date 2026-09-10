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
    int count = 0;

    pair<int, int> postOrder(TreeNode* node){

        if(node == NULL)
            return {0, 0};
        
        pair<int, int> left = postOrder(node->left);
        pair<int, int> right = postOrder(node->right);

        int nodeSum = left.first + right.first + node->val;
        int nodeCount = left.second + right.second + 1;

        if(node->val == (nodeSum / nodeCount))
            count++;
        
        return {nodeSum, nodeCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        
        postOrder(root);

        return count;
    }
};