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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int ans = 0;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while(!q.empty()){

            int mini = q.front().second;
            int size = q.size();
            int low, high;

            for(int i = 0; i < size; i++){

                int nodeId = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0)
                    low = nodeId;
                if(i == size - 1)
                    high = nodeId;
                
                if(node->left)
                    q.push({node->left, 2LL*nodeId + 1});
                if(node->right)
                    q.push({node->right, 2LL*nodeId + 2});
            }

            ans = max(ans, (high - low  + 1));
        }

        return ans;
    }
};