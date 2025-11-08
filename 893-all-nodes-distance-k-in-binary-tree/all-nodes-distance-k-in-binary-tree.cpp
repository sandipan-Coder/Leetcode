/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:

    void makeParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentOfNodes){

        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()){
            TreeNode* curr = nodes.front();
            nodes.pop();

            if(curr->left){
                parentOfNodes[curr->left] = curr;
                nodes.push(curr->left);
            }

            if(curr->right){
                parentOfNodes[curr->right] = curr;
                nodes.push(curr->right);
            }
        }

    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, TreeNode*> parentOfNodes;
        makeParents(root, parentOfNodes);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        vector<int> ans;

        q.push(target);
        visited[target] = true;
        int dist = 0;

        while(!q.empty()){

            int size = q.size();
            if(dist == k)
                break;

            for(int i = 0; i < size; i++){

                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }

                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }

                if(parentOfNodes[node] && !visited[parentOfNodes[node]]){
                    q.push(parentOfNodes[node]);
                    visited[parentOfNodes[node]] = true;
                }
            }
            dist++;
        }

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }

        return ans;
    }
};