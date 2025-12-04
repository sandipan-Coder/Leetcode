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

    /*
    int FloorFind(TreeNode* node, int &target){

        int floor = -1;

        while(node){

            if(node -> val == target)
                return target;
            
            if(node -> val > target)
                node = node -> left;
            else {

                floor = node -> val;
                node = node -> right;
            }
        }

        return floor;
    }

    int CeilFind(TreeNode* node, int &target){

        int ceil = -1;

        while(node){

            if(node -> val == target)
                return target;
            
            if(node -> val < target)
                node = node -> right;
            else {
                ceil = node -> val;
                node = node -> left;
            }
        }

        return ceil;
    }
    */

    void inorderTraversal(TreeNode* root, vector<int> &inorder){

        if(root == NULL)
            return;
        
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        
        vector<vector<int>> ans;
        vector<int> inorder;
        inorderTraversal(root, inorder);
        int n = inorder.size();

        for(int &qur: queries){

            if(qur < inorder[0])
                ans.push_back({-1, inorder[0]});
            else if (qur > inorder[n - 1])
                ans.push_back({inorder[n - 1], -1});
            else {

                auto lb = lower_bound(inorder.begin(), inorder.end(), qur);
                int val = *lb;
                if(val == qur)
                    ans.push_back({val, val});
                else {
                    int prev = *(lb - 1);
                    ans.push_back({prev, val});
                }
            }
        }

        return ans;
    }
};