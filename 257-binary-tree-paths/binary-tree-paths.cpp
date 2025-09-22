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

    void getPaths(TreeNode* node, string str, vector<string> &ans){

        str += to_string(node->val);  // Add the current node value to the path
        if (node->left) 
            getPaths(node->left, str + "->", ans);  // Traverse left
        if (node->right) 
            getPaths(node->right, str + "->", ans); // Traverse right
        if (!node->left && !node->right) 
            ans.push_back(str);  // Add path if leaf node
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        if(root == NULL)
            return ans;
        
        getPaths(root, "", ans);
        return ans;
    }
};