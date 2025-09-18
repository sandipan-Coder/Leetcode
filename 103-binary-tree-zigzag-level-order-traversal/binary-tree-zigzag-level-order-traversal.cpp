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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        
        queue<TreeNode*> nodeQ;
        bool leftToRight = true;
        nodeQ.push(root);

        while(!nodeQ.empty()){

            int size = nodeQ.size();
            vector<int> row(size);

            for(int i = 0; i < size; i++){

                TreeNode* node = nodeQ.front();
                nodeQ.pop();

                int idx = (leftToRight) ? i : (size - 1 - i);
                row[idx] = node->val;

                if(node->left)
                    nodeQ.push(node->left);
                if(node->right)
                    nodeQ.push(node->right);
            }

            leftToRight = !leftToRight;
            ans.push_back(row);
        }

        return ans;
    }
};